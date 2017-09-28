https://health.nokia.com/us/en/body

[Create Notification](https://api.health.nokia.com/notify?action=subscribe)
Notification lets your system be informed every time new data is available for a user. Nokia will call a provided url every time the user sync its Nokia device with its account.

[Request example - oAuth params omitted](https://developer.health.nokia.com/api/doc#api-Notification-notify_subscribe)
https://api.health.nokia.com/notify?
action=subscribe&
userid=Identifier&							// FHIR Patient Resource ID
callbackurl=http//www.fhirblocks.io/pusher.php&
startdate=1260350649&
enddate=1260350650&
appli=1&
comment=FHIR Convert and push




https:///www.fhirblocks.io/pusher.php?userid=Identifier&startdate=1260350649&enddate=1260350650&appli=1


[Nokia Weight Push](https://developer.health.nokia.com/api)
	"body":
	"updatetime": 1249409679,
	"timezone": "Europe/Paris",
	"measuregrps":
	"grpid": 2909,
	"attrib": 0,
	"date": 1222930968,
	"measures": "value": 178, "type": 1, "unit": -1




npm install fhirclient smart on fhir github.com/smart-on-fhir/client-js
npm install fhir-proof

npm i fhir-json-client



http://www.openhab.org

https://developer.health.nokia.com/api
API (api.health.nokia.com)
API Key	        4e42b240e0f47016938d0e93590fce45d08d6cdf9c4f82755d83632c74
API Secret      bdb50032b55f3698304e7c3344145165cb43fdf78d413e43b5c4fcd657d0
Callback URL    wbsapi.withings.net

API uses oAuth v1 with hmac-sha1 hashing algorithm.
Nonce and timestamps added to prevent replay attacks.
[oAuth spec](http://oauth.net/core/1.0/#signing_process)
[Base string example](http://oauth.net/core/1.0/#sig_base_example)
[Sample php code](https://developer.health.nokia.com/example_code.zip)
[Install OAuth Server](http://webkul.com/blog/ubuntu-oauth-installation/)
Use custom SNI or wbsapi.withings.net

oauth_token         727d61b9ee255701b785361491e8bbf8dbed91111c1b86293f3bb408718c
oauth_token_secret  c2d941f5702371bccd95cf29600b12bfb146d9d564683712c61f904
userid              14334347
deviceid            0

Parameter

Field       		   Opt  Type	    Description
userid      				Number	    Callback, url encoded
startdate   			y	unix epoch	measures start date
enddate					y	unix epoch	measures end date
lastupdate				y	unix epoch	measures since date
devtype					y	number		Deprecated - use meastype
meastype				y	number		Measure type
										- 1 : Weight (kg)
										- 4 : Height (meter)
										- 5 : Fat Free Mass (kg)
										- 6 : Fat Ratio (%)
										- 8 : Fat Mass Weight (kg)
										- 9 : Diastolic Blood Pressure (mmHg)
										- 10 : Systolic Blood Pressure (mmHg)
										- 11 : Heart Pulse (bpm)
										- 12 : Temperature
										- 54 : SP02(%)
										- 71 : Body Temperature
										- 73 : Skin Temperature
										- 76 : Muscle Mass
										- 77 : Hydration
										- 88 : Bone Mass
										- 91 : Pulse Wave Velocity
category				y	number		- 1 for real measurements
										- 2 for user objectives
limit 					y	number		max number of measure groups to return
offset 					y	number		skip offset can be comb w/ limit
oauth_consumer_key			string		consumer key provided by Nokia
oauth_nonce					string		random string different for every request
oauth_signature				string		oAuth hmac-sha1 base string
										- consumer secret + '&' + oauth token secret
										- base64 & url-encode
oauth_signature_method		string		HMAC-SHA1
oauth_timestamp				unix epoch	current date
oauth_token					string		oAuth token
										- user authorization > request token
										- data query > access token
oauth_version				number		1.0


http://api.health.nokia.com/measure?action=getmeas&oauth_consumer_key=4e42b240e0f47016938d0e93590fce45d08d6cdf9c4f82755d83632c74&oauth_nonce=8e6df6ae199ebe68b7b32433e83af779&oauth_signature=NKt7frxQ96%2BtVl2n4xcgimZMi4E%3D&oauth_signature_method=HMAC-SHA1&oauth_timestamp=1505918174&oauth_token=727d61b9ee255701b785361491e8bbf8dbed91111c1b86293f3bb408718c&oauth_version=1.0&userid=https://developer.health.nokia.com/account/authorize?oauth_consumer_key=4e42b240e0f47016938d0e93590fce45d08d6cdf9c4f82755d83632c74&oauth_nonce=54c30027d843ed115ff74d9c5a01fbdf&oauth_signature=EpRkDwvafAte8b5vYidDbI6MXYo%3D&oauth_signature_method=HMAC-SHA1&oauth_timestamp=1505917995&oauth_token=841c8cd5b77eb1dfd981230e10b7c87e69b387797dccce52359f69&oauth_version=1.0

http://api.health.nokia.com/measure?
action=getmeas&
oauth_consumer_key=4e42b240e0f47016938d0e93590fce45d08d6cdf9c4f82755d83632c74&
oauth_nonce=8e6df6ae199ebe68b7b32433e83af779&
oauth_signature=NKt7frxQ96%2BtVl2n4xcgimZMi4E%3D&
oauth_signature_method=HMAC-SHA1&
oauth_timestamp=1505918174&
oauth_token=727d61b9ee255701b785361491e8bbf8dbed91111c1b86293f3bb408718c&
oauth_version=1.0&

userid=https://developer.health.nokia.com/account/authorize?
oauth_consumer_key=4e42b240e0f47016938d0e93590fce45d08d6cdf9c4f82755d83632c74&
oauth_nonce=54c30027d843ed115ff74d9c5a01fbdf&
oauth_signature=EpRkDwvafAte8b5vYidDbI6MXYo%3D&
oauth_signature_method=HMAC-SHA1&
oauth_timestamp=1505917995&
oauth_token=841c8cd5b77eb1dfd981230e10b7c87e69b387797dccce52359f69&
oauth_version=1.0

```JSON
{
           "status": 0,
           "body": {
               "updatetime": 1249409679,
               "timezone": "Europe/Paris",
               "measuregrps": [
                   {
                       "grpid": 2909,
                       "attrib": 0,
                       "date": 1222930968,
                       "category": 1,
                       "measures": [
                           {
                               "value": 79300,
                               "type": 1,
                               "unit": -3
                           },
                           {
                               "value": 652,
                               "type": 5,
                               "unit": -1
                           },
                           {
                               "value": 178,
                               "type": 6,
                               "unit": -1
                           },
                           {
                               "value": 14125,
                               "type": 8,
                               "unit": -3
                           }
                       ]
                   },
                   {
                       "grpid": 2908,
                       "attrib": 0,
                       "date": 1222930968,
                       "category": 1,
                       "measures": [
                           {
                               "value": 173,
                               "type": 4,
                               "unit": -2
                           }
                       ]
                   }
               ]
           }
}
```
