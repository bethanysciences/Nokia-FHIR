# Use Cases for The FHIRBlocks Project
Version 0.0.1
20170921

##Introduction
The FHIRBlocks Project is developing a first-generation self-sovereign identity and hyper-granular authorization services allowing mHealth applications and healthcare providers to govern and transact electronic health records (EHR) with absolute security.

FHIRBlocks defines a protocol, Supplemental Methods of Open Access Control (SMOAC), overlaying Hyperledger blockchain-based self-sovereign identity and authorization management capabilities enhancing HL7's Fast Health Interoperability Resource (FHIR) EHR standards transactions without modification.

Our goal enables interested parties to rapidly develop applications taking advantage of FHIRBlocks benefits.

EHR transaction authorization and exchange uses two services:
	1. (SMOAC protocol) self-sovereign identity and permissions management
		- Manage users or applications access and EHR permissions
		a. Registration and revocation (Authorization, Authentication and Accounting (AAA))
		b. EHR transaction governance (examples)
			i. multi-lateral EHR access authorization (patient safety restricts EHR access)
			ii. pre-loaded condition modification (living will provision, organ donation, telematic data spike)
			iii. permission time to live (TTL)
			iv. field level permission granularity (diastolic BP measure only)
			v. permissions (read, write, execute, modify, read and execute, full)
			vi. authorized third party access (family, employers, payors)
			vi. other parameters as conditions suggest
		c. Every exchange is recorded and additive forming immutable ledger of transactions
	2. EHR FHIR exchange
		- EHR State tagged transactions flow directly between authorized applications.

The use cases outlined below illustrate prototypical and representative FHIRBlocks transactions.

## Case 1 Digiceutical Weight Watching
###Introduction
Close post-operative vital sign management speeds recovery and lessens complications often leading to patient re-admission. This use case is the prescription of an off the shelf IoT connected scale to monitor patient weight on a daily basis or as required in the treatment protocol.

This case illustrates FHIRBlocks benefits integrating multiple systems without modification and adding absolute security and hyper-granular patient / provider EHR governance.  

### Actors
* Patient: Healthcare recipient (or authorized designate) authorizing EHR permissions and transactions.
* Provider: organization with FHIR compliant EHR resource server and system and offering post-op patient a connected scale digiceutical to monitor weight critical to preventing re-admission.
* SMOAC: Authenticates the Pusher to write EHR data on behalf of the patient, in accordance with legal and institutional policies
* Scale: Records patient daily weight and pushes measure to cloud based App Server
* App Server: Persists captured weight measures data
* Pusher Function: Pulls new App Server weight measures, translates (if necessary) to FHIR format and pushes SMOAC authorized records to FRS. Can sit inside App Server or FRS or as an independent service.
* FHIR Resource Server (FRS): FHIR compliant server used by Provider to hold and retrieve EHR data as authorized
* Clinician: charged with patient prognosis alerted to out of limit weight measures for attention and coaching to reduce re-admission

### Pre-conditions (outside the scope of this use case)
* All actors authentic and authorized permissions set in FHIRBlocks.
* Pusher Function exists as an independent service function.
* Scale records weight, pushes weight measure to cloud-based App Server accessible through an open API such as OAuth/REST/JSON-LD
* All data repositories and transaction methods operate in compliance with HIPAA Privacy and Security Rules.
* All data repositories and transaction methods operate in compliance with Provider privacy and security policy
* Provider identity-proofed and issued authentic credentials to that identity and role
* Provider holds Patient EHR data

### Post-conditions
* Any actor at any time can alter authorized permissions tearing down the data flows.

### Basic Flow
0.1 Clinician prescribes weight monitoring Digiceutical (Scale and App Server)
0.2 Patient receives and connects Scale w/ or w/o installation
0.3.1 Patient authorizes and sets permissions for scale data to be sent to Provider and other Authorized parties (Payor)
0.3.2 Provider authorizes and sets permissions for scale data and Patient EHR and other Authorized parties (family)

1.0 Patient steps on Scale recording weight record
2.0 Scale pushes record App Server
3.0 Pusher Function pulls record from App Server
4.0 Pusher Function translates record to FHIR format
5.0 Pusher Function transmits record to FRS
6.0 FRS loads record into Patient EHR
7.0 FRS checks for out of limit condition and pushing alert to Clinician
8.0 Clinician reviews alert taking necessary preventative actions

### UML Diagram


### Architecture
