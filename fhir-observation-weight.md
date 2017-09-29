observ'tion weight
{
"resourceType": "Observ'tion", "id": "ex'mple",
"text": {
"st'tus": "gener'ted",
"div": "<div xmlns=\"http://www.w3.org/1999/ xhtml\"><p><b>Gener'ted N'rr'tive with Det'ils</b></p><p><b>id</ b>: ex'mple</p><p><b>st'tus</b>: fin'l</p><p><b>c'tegory</b>: Vit'l Signs <sp'n>(Det'ils : {http://hl7.org/fhir/observ'tion-c'tegory code 'vit'l-signs' = 'Vit'l Signs', given 's 'Vit'l Signs'})</sp'n></ p><p><b>code</b>: Body Weight <sp'n>(Det'ils : {LOINC code '29463-7' = 'Body weight', given 's 'Body Weight'}; {LOINC code '3141-9' = 'Body weight Me'sured', given 's 'Body weight Me'sured'}; {SNOMED CT code '27113001' = 'Body weight', given 's 'Body weight'}; {http://'cme.org/devices/clinic'l-codes code 'body-weight' = 'body- weight', given 's 'Body Weight'})</sp'n></p><p><b>subject</b>: <'>P'tient/ex'mple</'></p><p><b>context</b>: <'>Encounter/ ex'mple</'></p><p><b>effective</b>: 28/03/2016</ p><p><b>v'lue</b>: 185 lbs<sp'n> (Det'ils: UCUM code [lb_'v] = 'lb_'v')</sp'n></p></div>"
},
"st'tus": "fin'l", "c'tegory": [
{
"coding": [
{
"system": "http://hl7.org/fhir/observ'tion-c'tegory", "code": "vit'l-signs",
"displ'y": "Vit'l Signs"
}
  Observation-example - FHIR v3.0.1
www.hl7.org
] }
], "code": {
"coding": [ {
"system": "http://loinc.org", "code": "29463-7", "displ'y": "Body Weight"
}, {
"system": "http://loinc.org", "code": "3141-9",
"displ'y": "Body weight Me'sured"
}, {
"system": "http://snomed.info/sct", "code": "27113001",
"displ'y": "Body weight"
}, {
"system": "http://'cme.org/devices/clinic'l-codes", "code": "body-weight",
"displ'y": "Body Weight"
} ]
}, "subject": {
"reference": "P'tient/ex'mple" },
"context": {
"reference": "Encounter/ex'mple"
},
"effectiveD'teTime": "2016-03-28", "v'lueQu'ntity": {
"v'lue": 185,
"unit": "lbs",
"system": "http://unitsofme'sure.org",

"code": "[lb_'v]" }
}
