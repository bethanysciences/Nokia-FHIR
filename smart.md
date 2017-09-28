SMART: Tech Stack for Health Apps
SMART on FHIR is a set of open specifications to integrate apps with Electronic Health Records, portals, Health Information Exchanges, and other Health IT systems. You get…
Clean, structured data:  FHIR
Easy-to-use, resource-oriented REST API for structured clinical data. Grab a resource with:
$ curl https://sb-fhir-dstu2.smarthealthit.org/api/smartdstu2/open/Patient/SMART-1551992 \
       -H 'Accept: application/json'
{
  "resourceType": "Patient",
  "active": true,
  "name": [{
      "use": "official",
      "family": ["Coleman"],
      "given": ["Lisa","P."]
  }],
  "gender": "female",
  "birthDate": "1948-04-14",
  ...
}
Scopes and permissions:  OAuth2
When an EHR user launches your app, you get a “launch request” notification. Just ask for the permissions you need using OAuth scopes like patient/*.read and once you’re authorized you’ll have an access token with the permissions you need – including access to clinical data and context like:
•	which patient is in-context in the EHR
•	which encounter is in-context in the EHR
•	the physical location of the EHR user
Simple sign-in:  OpenID Connect
If your app needs to authenticate the EHR end-user, OpenID Connect is there to help. Just ask for one additional scope (openid) when you request authorization, and you’ll have access to a UserInfo endpoint that exposes structure claims about the user, including name and NPI.
Lightweight UI integration:  HTML5
Need to hook your app into an existing EHR user interface? SMART on FHIR allows web apps to run inside browser widgets or inline frames, so users can interact without leaving the EHR environment. Of course, native and mobile apps are supported too – so you can choose the level of integration that makes sense for you.
http://engineering.cerner.com/smart-on-fhir-tutorial/#introduction


Resource Patient - Content http://www.hl7.org/implement/standards/fhir/patient.html#8.1
The data in the Resource covers the "who" information about the patient: its attributes are focused on the demographic information necessary to support the administrative, financial and logistic procedures. A Patient record is generally created and maintained by each organization providing care for a patient. A patient or animal receiving care at multiple organizations may therefore have its information present in multiple Patient Resources.
Not all concepts are included within the base resource (such as race, ethnicity, organ donor status, nationalilty, etc.), but may be found in profiles defined for specific jurisdictions (e.g., US Meaningful Use Program) or standard extensions.
Such fields vary widely between jurisdictions and often have different names and valuesets for the similar concepts, but they are not similar enough to be able to map and exchange

Resource Observation - Content
This resource is an event resource from a FHIR workflow perspective - see Workflow.
Observations are a central element in healthcare, used to support diagnosis, monitor progress, determine baselines and patterns and even capture demographic characteristics. Most observations are simple name/value pair assertions with some metadata, but some observations group other observations together logically, or even are multi-component observations. Note that the  DiagnosticReport resource provides a clinical or workflow context for a set of observations and the Observation resource is referenced by DiagnosticReport to represent lab, imaging, and other clinical and diagnostic data to form a complete report.
JSON Template
{
  "resourceType" : "Observation",
  // from Resource: id, meta, implicitRules, and language
  // from DomainResource: text, contained, extension, and modifierExtension
  "identifier" : [{ Identifier }], // Business Identifier for observation
  "basedOn" : [{ Reference(CarePlan|DeviceRequest|ImmunizationRecommendation|
   MedicationRequest|NutritionOrder|ProcedureRequest|ReferralRequest) }], // Fulfills plan, proposal or order
  "status" : "<code>", // R!  registered | preliminary | final | amended +
  "category" : [{ CodeableConcept }], // Classification of  type of observation
  "code" : { CodeableConcept }, // R!  Type of observation (code / type)
  "subject" : { Reference(Patient|Group|Device|Location) }, // Who and/or what this is about
  "context" : { Reference(Encounter|EpisodeOfCare) }, // Healthcare event during which this observation is made
  // effective[x]: Clinically relevant time/time-period for observation. One of these 2:
  "effectiveDateTime" : "<dateTime>",
  "effectivePeriod" : { Period },
  "issued" : "<instant>", // Date/Time this was made available
  "performer" : [{ Reference(Practitioner|Organization|Patient|RelatedPerson) }], // Who is responsible for the observation
  // value[x]: Actual result. One of these 11:
  "valueQuantity" : { Quantity },
  "valueCodeableConcept" : { CodeableConcept },
  "valueString" : "<string>",
  "valueBoolean" : <boolean>,
  "valueRange" : { Range },
  "valueRatio" : { Ratio },
  "valueSampledData" : { SampledData },
  "valueAttachment" : { Attachment },
  "valueTime" : "<time>",
  "valueDateTime" : "<dateTime>",
  "valuePeriod" : { Period },
  "dataAbsentReason" : { CodeableConcept }, // C? Why the result is missing
  "interpretation" : { CodeableConcept }, // High, low, normal, etc.
  "comment" : "<string>", // Comments about result
  "bodySite" : { CodeableConcept }, // Observed body part
  "method" : { CodeableConcept }, // How it was done
  "specimen" : { Reference(Specimen) }, // Specimen used for this observation
  "device" : { Reference(Device|DeviceMetric) }, // (Measurement) Device
  "referenceRange" : [{ // Provides guide for interpretation
    "low" : { Quantity(SimpleQuantity) }, // C? Low Range, if relevant
    "high" : { Quantity(SimpleQuantity) }, // C? High Range, if relevant
    "type" : { CodeableConcept }, // Reference range qualifier
    "appliesTo" : [{ CodeableConcept }], // Reference range population
    "age" : { Range }, // Applicable age range, if relevant
    "text" : "<string>" // Text based reference range in an observation
  }],
  "related" : [{ // Resource related to this observation
    "type" : "<code>", // has-member | derived-from | sequel-to | replaces | qualified-by | interfered-by
    "target" : { Reference(Observation|QuestionnaireResponse|Sequence) } // R!  Resource that is related to this one
  }],
  "component" : [{ // Component results
    "code" : { CodeableConcept }, // R!  Type of component observation (code / type)
    // value[x]: Actual component result. One of these 10:
    "valueQuantity" : { Quantity },
    "valueCodeableConcept" : { CodeableConcept },
    "valueString" : "<string>",
    "valueRange" : { Range },
    "valueRatio" : { Ratio },
    "valueSampledData" : { SampledData },
    "valueAttachment" : { Attachment },
    "valueTime" : "<time>",
    "valueDateTime" : "<dateTime>",
    "valuePeriod" : { Period },
    "dataAbsentReason" : { CodeableConcept }, // C? Why the component result is missing
    "interpretation" : { CodeableConcept }, // High, low, normal, etc.
    "referenceRange" : [{ Content as for Observation.referenceRange }] // Provides guide for interpretation of component result
  }]
}

This value set is used in the following places:

This value set is the designated 'entire code system' value set for Observation Category Codes
Observation.category (Preferred)
StructureDefinition DeviceMetricObservation: Observation.category ((Preferred))
StructureDefinition Observation-Genetics: Observation.category ((Preferred))
StructureDefinition VitalSigns: Observation.category ((Preferred))
StructureDefinition BodyWeight: Observation.category ((Preferred))
StructureDefinition RespRate: Observation.category ((Preferred))
StructureDefinition HeartRate: Observation.category ((Preferred))
StructureDefinition BodyTemp: Observation.category ((Preferred))
StructureDefinition BodyHeight: Observation.category ((Preferred))
StructureDefinition BodyLength: Observation.category ((Preferred))
StructureDefinition HeadCircum: Observation.category ((Preferred))
StructureDefinition OxygenSat: Observation.category ((Preferred))
StructureDefinition BMI: Observation.category ((Preferred))
StructureDefinition BP: Observation.category ((Preferred))
StructureDefinition VitalsPanel: Observation.category ((Preferred))
StructureDefinition Cholesterol: Observation.category ((Preferred))
StructureDefinition Triglyceride: Observation.category ((Preferred))
StructureDefinition HDLCholesterol: Observation.category ((Preferred))
StructureDefinition LDLCholesterol: Observation.category ((Preferred))

FHIR Body Weight Profile http://hl7.org/fhir/StructureDefinition/bodyweight
