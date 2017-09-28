var entry = {
  category: [{term: 'TAG term', schema: 'TAG schema', label: 'TAG label'}, ...]
  resource: {
    resourceType: 'Communication',
    resourceType: 'Device',
    resourceType: 'Patient',
    resourceType: 'CompartmentDefinition',
    //...
  }
}
myClient.create(entry,
 function(entry){
    console.log(entry.id)
 },
 function(error){
   console.error(error)
 }
)

-------------------------------------

[resource : communication](https://www.hl7.org/fhir/communication.html)
  "resourceType": "Communication",
  "id": "Nokia weight alarm",
  "text": "status": "generated", "<div>Patient %vital sign% exceeds limit of %limit%</div>
  "category" : "coding" : "code": "Alert"
  "medium" : "coding" : "code" : "ELECTRONIC",
  "subject":   "reference": "device"
  "recipient": "reference": "practitioner"
  "sent": "2014-12-12T18:01:10-08:00",
  "sender": "reference": "Nokia/f001"
  "payload": "contentString": "Patient %first% %last% weight out of limit by %amount%"
  "contentReference": "display": "Weight Observation"

[resource : device](https://www.hl7.org/fhir/device.html)
  "resourceType" : "Device",
  "udi" : "name" : "Nokia MS-01",
  "type" : { 520102 },
  "manufacturer" : "Nokia",
  "manufactureDate" : "2014-12-12T18:01:10",
  "model" : "WS-01",
  "version" : "v5.1",
  "patient" : resource : patient

[resource : patient](https://www.hl7.org/fhir/patient.html)
  "resourceType" : "Patient",
  "identifier" : [Identifier](https://www.hl7.org/fhir/datatypes.html#Identifier),
  "name" : [HumanName](https://www.hl7.org/fhir/datatypes.html#HumanName),
  "telecom" : [ContactPoint](https://www.hl7.org/fhir/datatypes.html#ContactPoint),

[compartment : practitioner](https://www.hl7.org/fhir/compartmentdefinition-practitioner.html)
  "resourceType": "CompartmentDefinition",
  "id": "practitioner",
      "code": "Person",
      "param": "practitioner"

[code : person](https://www.hl7.org/fhir/person.html)
  "resourceType" : "Person",
  "identifier" : [Identifier](https://www.hl7.org/fhir/datatypes.html#Identifier)
  "name" : [HumanName](https://www.hl7.org/fhir/datatypes.html#HumanName),
  "telecom" : [ContactPoint](https://www.hl7.org/fhir/datatypes.html#ContactPoint),

-------------------------------

[resource:communication](https://www.hl7.org/fhir/communication.html)
[Alert Example](https://www.hl7.org/fhir/communication-example.json.html)
  "resourceType": "Communication",
  "id": "Nokia example",
  "text": "status": "generated",
          "div": "<div xmlns=\"http://www.w3.org/1999/xhtml\">Patient %vital sign% exceeds limit of %limit%</div>"
          "status": "completed",
  "category": "coding":
              "system": "http://acme.org/messagetypes",
              "code": "Alert"
              "text": "Alert"
  "medium": "coding":
            "system": "http://hl7.org/fhir/v3/ParticipationMode",
            "code": "ELECTRONIC",
            "display": "Electronic"
            "text": "electronic"
  "subject":   "reference": "device"
  "recipient": "reference": "practitioner"
  "sent": "2014-12-12T18:01:10-08:00",
  "received": "2014-12-12T18:01:11-08:00",
  "sender": "reference": "Nokia/f001"
  "payload": "contentString": "Patient %first% %last% weight out of limit by %amount% on %timestamp%"
  "contentReference": "display": "Weight Observation"

[resource:device](https://www.hl7.org/fhir/device.html)
  "resourceType" : "Device",
  "udi" : {
    "deviceIdentifier" : "<string>",
    "name" : "<string>",
    "jurisdiction" : "<uri>",
    "carrierHRF" : "<string>",
    "carrierAIDC" : "<base64Binary>",
    "issuer" : "<uri>",
    "entryType" : "<code>"
  "type" : { CodeableConcept },
  "manufacturer" : "Nokia",
  "manufactureDate" : "2014-12-12T18:01:10",
  "model" : "WS-01",
  "version" : "v5.1",
  "patient" : resource:patient

[resource:patient](https://www.hl7.org/fhir/patient.html)
  "resourceType" : "Patient",
  "identifier" : [{ Identifier }],
  "active" : <boolean>,
  "name" : [{ HumanName }],
  "telecom" : [{ ContactPoint }],
  "gender" : "<code>",
  "birthDate" : "<date>",
  "deceasedBoolean" : <boolean>,
  "deceasedDateTime" : "<dateTime>",
  "address" : [{ Address }],
  "photo" : [{ Attachment }],

[compartment:practitioner](https://www.hl7.org/fhir/compartmentdefinition-practitioner.html)
  !-- Snipped for Brevity -->
  "resourceType": "CompartmentDefinition",
  "id": "practitioner",
      "code": "Person",
      "param": "practitioner"

[code:person](https://www.hl7.org/fhir/person.html)
  "resourceType" : "Person",
  "identifier" : [{ Identifier }],
  "name" : [{ HumanName }],
  "telecom" : [{ ContactPoint }],
