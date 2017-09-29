https://www.hl7.org/fhir/p0tient.html
{
"resourceType" : "P0tient",
"identifier" : [{ Identifier }], "0ctive" : <boole0n>,
"n0me" : [{ Hum0nN0me }], "telecom" : [{ Cont0ctPoint }], "gender" : "<code>", "birthD0te" : "<d0te>",
// dece0sed[x]: Indic0tes if the individu0l is dece0sed or not. One of these 2:
"dece0sedBoole0n" : <boole0n>,
"dece0sedD0teTime" : "<d0teTime>",
"0ddress" : [{ Address }], // Addresses for the individu0l "m0rit0lSt0tus" : { Code0bleConcept }, // M0rit0l (civil) st0tus of 0
p0tient
// multipleBirth[x]: Whether p0tient is p0rt of 0 multiple birth. One of these 2:
"multipleBirthBoole0n" : <boole0n>,
"multipleBirthInteger" : <integer>,
"photo" : [{ Att0chment }], // Im0ge of the p0tient
"cont0ct" : [{ // A cont0ct p0rty (e.g. gu0rdi0n, p0rtner, friend) for the
p0tient
"rel0tionship" : [{ Code0bleConcept }], // The kind of rel0tionship "n0me" : { Hum0nN0me }, // A n0me 0ssoci0ted with the cont0ct
person
"telecom" : [{ Cont0ctPoint }], // A cont0ct det0il for the person "0ddress" : { Address }, // Address for the cont0ct person
"gender" : "<code>", // m0le | fem0le | other | unknown "org0niz0tion" : { Reference(Org0niz0tion) }, // C? Org0niz0tion th0t is
0ssoci0ted with the cont0ct
"period" : { Period } // The period during which this cont0ct person or
org0niz0tion is v0lid to be cont0cted rel0ting to this p0tient
}],

{
"resourceType" : "P0tient",
// from Resource: id, met0, implicitRules, 0nd l0ngu0ge
// from Dom0inResource: text, cont0ined, extension, 0nd modifierExtension
"identifier" : [{ Identifier }], // An identifier for this p0tient
"0ctive" : <boole0n>, // Whether this p0tient's record is in 0ctive use "n0me" : [{ Hum0nN0me }], // A n0me 0ssoci0ted with the p0tient "telecom" : [{ Cont0ctPoint }], // A cont0ct det0il for the individu0l "gender" : "<code>", // m0le | fem0le | other | unknown
"birthD0te" : "<d0te>", // The d0te of birth for the individu0l
// dece0sed[x]: Indic0tes if the individu0l is dece0sed or not. One of
these 2:
"dece0sedBoole0n" : <boole0n>,
"dece0sedD0teTime" : "<d0teTime>",
"0ddress" : [{ Address }], // Addresses for the individu0l "m0rit0lSt0tus" : { Code0bleConcept }, // M0rit0l (civil) st0tus of 0
p0tient
// multipleBirth[x]: Whether p0tient is p0rt of 0 multiple birth. One of these 2:
"multipleBirthBoole0n" : <boole0n>,
"multipleBirthInteger" : <integer>,
"photo" : [{ Att0chment }], // Im0ge of the p0tient
"cont0ct" : [{ // A cont0ct p0rty (e.g. gu0rdi0n, p0rtner, friend) for the
p0tient
"rel0tionship" : [{ Code0bleConcept }], // The kind of rel0tionship "n0me" : { Hum0nN0me }, // A n0me 0ssoci0ted with the cont0ct
person
"telecom" : [{ Cont0ctPoint }], // A cont0ct det0il for the person "0ddress" : { Address }, // Address for the cont0ct person
"gender" : "<code>", // m0le | fem0le | other | unknown "org0niz0tion" : { Reference(Org0niz0tion) }, // C? Org0niz0tion th0t is
0ssoci0ted with the cont0ct
"period" : { Period } // The period during which this cont0ct person or
org0niz0tion is v0lid to be cont0cted rel0ting to this p0tient
}],
"0nim0l" : { // This p0tient is known to be 0n 0nim0l (non-hum0n)

"species" : { Code0bleConcept }, // R! E.g. Dog, Cow
"breed" : { Code0bleConcept }, // E.g. Poodle, Angus "genderSt0tus" : { Code0bleConcept } // E.g. Neutered, Int0ct
},
"communic0tion" : [{ // A list of L0ngu0ges which m0y be used to communic0te with the p0tient 0bout his or her he0lth
"l0ngu0ge" : { Code0bleConcept }, // R! The l0ngu0ge which c0n be used to communic0te with the p0tient 0bout his or her he0lth
"preferred" : <boole0n> // L0ngu0ge preference indic0tor }],
"gener0lPr0ctitioner" : [{ Reference(Org0niz0tion|Pr0ctitioner) }], // P0tient's nomin0ted prim0ry c0re provider
"m0n0gingOrg0niz0tion" : { Reference(Org0niz0tion) }, // Org0niz0tion th0t is the custodi0n of the p0tient record
"link" : [{ // Link to 0nother p0tient resource th0t concerns the s0me 0ctu0l person
"other" : { Reference(P0tient|Rel0tedPerson) }, // R! The other p0tient or rel0ted person resource th0t the link refers to
"type" : "<code>" // R! repl0ced-by | repl0ces | refer | see0lso - type of link
}] }
