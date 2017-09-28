jasmine.DEFAULT_TIMEOUT_INTERVAL = 10000

fhir = require('../src/adapters/yui')

describe "yui", ->

  subject = fhir
      baseUrl: 'https://ci-api.fhir.me',
      patient: '123',
      auth: {user: 'client', pass: 'secret'}
  mkfail = (done)->
    (err)->
      console.error(err)
      done()

  it 'simplest', (done) ->
    console.log('yui: simplest')
    success = (data, status, headers)->
      expect(status).toBe(200)
      expect(data).not.toBe(1)
      expect(headers).not.toBe(null)
      done()
    error = mkfail(done)

    subject.search(type: 'Patient', query: {name: 'maud'}, success: success, error: error)

  it "can convert results to an in-memory graph", (done) ->
    console.log('yui: can convert ...')
    success = (data, status, headers)->
      expect(data[0].subject.resourceType).toBe('Patient')
      done()
    error = mkfail(done)

    subject.search(type: 'Observation', graph: true, query: {$include: {Observation: 'subject'}}, success: success, error: error)

  it "can post", (done) ->
    console.log('yui: can post ...')
    exampleSecEvent = {
      "resourceType": "SecurityEvent",
      "event": {
        "type": {
          "coding": [{
            "system": "http://nema.org/dicom/dcid",
            "code": "110114",
            "display": "User Authentication"
          }]
        },
        "subtype": [{
          "coding": [{
            "system": "http://nema.org/dicom/dcid",
            "code": "110122",
            "display": "Login"
          }]
        }],
        "action": "E",
        "dateTime": "2014-09-13T13:48:42Z",
        "outcome": "0"
      },
      "participant": [{
        "userId": "service",
        "network": {
          "identifier": "service",
          "type": "2"
        }
      }],
      "source": {
        "site": "Cloud",
        "identifier": "Health Intersections",
        "type": [{
          "system": "http://hl7.org/fhir/security-source-type",
          "code": "3",
          "display": "Web Server"
        }]
      }
    }

    success = (data, status, headers)-> done()
    error = mkfail(done)

    subject.create {entry: {content: exampleSecEvent}, success: success, error: error}

  it "can resolve refs", (done) ->
    console.log('yui: can resolve ...')
    success = (rxs, status, headers)->
      rx = rxs.entry[0].content
      med = subject.resolveSync
        reference: rx.medication
        resource: rx
        bundle: rx
      expect(med.content).toBeTruthy()
      done()
    error = mkfail(done)

    subject.search
      type: 'MedicationPrescription'
      query:
        $include:
          MedicationPrescription: 'medication'
      success: success
      error: error
