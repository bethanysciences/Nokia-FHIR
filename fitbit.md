https://dev.fitbit.com/apps/details/228BBZ
https://tomhummel.com/2016/03/19/fitbit-heart-rate/
  
OAuth 2.0 Client ID		228BBZ  
Client Secret			c92390e25136611a1616d1dd78f687ce  
Callback URL			https://www.getpostman.com/oauth2/callback  
OAuth 2.0: Authorization URI					https://www.fitbit.com/oauth2/authorize  
OAuth 2.0: Access/Refresh Token Request URI		https://api.fitbit.com/oauth2/token 
  
1. Get secret 
```
https://www.fitbit.com/oauth2/authorize?response_type=code&client_id=228BBZ&redirect_uri=https%3A%2F%2Fwww.getpostman.com%2Foauth2%2Fcallback&scope=weight&expires_in=604800
```
code=		ff668def405b31b62362e704a7b80b7793d4c8c4

2. Create Authorization: Basic - base64(client id + code)
```
echo -n '228BBZ:ff668def405b31b62362e704a7b80b7793d4c8c4' | openssl base64
```

3. Get access and refresh tokens
```
curl \-X POST \--header "Content-Type: application/x-www-form-urlencoded" \--header "Authorization: Basic MjI4QkJaOmZmNjY4ZGVmNDA1YjMxYjYyMzYyZTcwNGE3YjgwYjc3OTNkNGM4YzQ=" \https://api.fitbit.com/oauth2/token?client_id=228BBZ&grant_type=authorization_code&redirect_uri=https://www.getpostman.com/oauth2/callback&code=ff668def405b31b62362e704a7b80b7793d4c8c4
```

3. Submit for token and refresh token at fitbit debug tool
```
curl	-X POST -i
-H 'Authorization: Basic MjI4QkJaOmM5MjM5MGUyNTEzNjYxMWExNjE2ZDFkZDc4ZjY4N2Nl'
-H 'Content-Type: application/x-www-form-urlencoded' 
-d "clientId=228BBZ" 
-d "grant_type=authorization_code" 
-d "redirect_uri=https%3A%2F%2Fwww.getpostman.com%2Foauth2%2Fcallback" 
-d "code=ff668def405b31b62362e704a7b80b7793d4c8c4" 
https://api.fitbit.com/oauth2/token
```
Response  
```
{"access_token":"eyJhbGciOiJIUzI1NiJ9.eyJzdWIiOiIyNE5XTjMiLCJhdWQiOiIyMjhCQloiLCJpc3MiOiJGaXRiaXQiLCJ0eXAiOiJhY2Nlc3NfdG9rZW4iLCJzY29wZXMiOiJyd2VpIiwiZXhwIjoxNDk1NDk2NDY0LCJpYXQiOjE0OTU0Njc2NjR9.euBd0l94G_yY5vDH1qmlRm0TLM7QNGUn4z3aKXrXgMc",
"expires_in":28800,
"refresh_token":"337a8e786c82c66335a72dfa3f1e40bf4b98b5f3aaf03eb24c7670b463a61bd1",
"scope":"weight",
"token_type":"Bearer",
"user_id":"24NWN3"}
```
  
4. REQUEST WEIGHT
curl -X GET \
  -H "Authorization: Bearer eyJhbGciOiJIUzI1NiJ9.eyJzdWIiOiIyNE5XTjMiLCJhdWQiOiIyMjhUTVAiLCJpc3MiOiJGaXRiaXQiLCJ0eXAiOiJhY2Nlc3NfdG9rZW4iLCJzY29wZXMiOiJ3aHIgd251dCB3cHJvIHdzbGUgd3dlaSB3c29jIHdzZXQgd2FjdCB3bG9jIiwiZXhwIjoxNDk1NDk0MTQ0LCJpYXQiOjE0OTU0NjUzNDR9.17RelR4XQc3IXwjdByFpD72CkjR5pR5ddAmQtGvp_e0" \
  "https://api.fitbit.com/1/user/-/body/log/weight/date/2016-09-01/1m.json"

--------------------------------
#REFRESH TOKEN
curl \
  -X POST \
  --header "Content-Type: application/x-www-form-urlencoded" \
  --header "Authorization: Basic QUJDMTIzOjEyMzQ1Njc4MTIzNDU2NzgxMjM0NTY3ODEyMzQ1Njc4" \
  https://api.fitbit.com/oauth2/token?client_id=24NWN3&grant_type=refresh_token&refresh_token=7654ASdf7654ASdf7654ASdf7654ASdf7654ASdf7654ASdf7654ASdf7654ASdf
--------------------------------
Weight
user-id		Encoded user ID use "-" (dash) for current logged-in user
date		Date (yyyy-MM-dd)
base-date	End date when period provided (yyyy-MM-dd) Start date when date range provided.
period		Period (1d, 7d, 30d, 1w, 1m)
end-date	End date when date range provided (< 32 days)

GET https://api.fitbit.com/1/user/[user-id]/body/log/weight/date/[base-date]/[period].json
GET https://api.fitbit.com/1/user/24NWN3/body/log/weight/date/2016-09-01/1m.json

MAY 2013 >
2013-01-01
2013-02-01
2013-03-01
2013-04-01
2013-05-01
2013-06-01
2013-01-01
2013-08-01
2013-09-01
2013-10-01
2013-11-01
2013-12-01
2014-01-01
2014-02-01
2014-03-01
2014-04-01
2014-05-01
2014-06-01
2014-01-01
2014-08-01
2014-09-01
2014-10-01
2014-11-01
2014-12-01
2015-01-01
2015-02-01
2015-03-01
2015-04-01
2015-05-01
2015-06-01
2015-01-01
2015-08-01
2015-09-01
2015-10-01
2015-11-01
2015-12-01
2016-01-01
2016-02-01
2016-03-01
2016-04-01
2016-05-01
2016-06-01
2016-01-01
2016-08-01
2016-09-01
2016-10-01
2016-11-01
2016-12-01