# Withings Toolbox

[![CircleCI](https://circleci.com/gh/milanito/withings-toolbox.svg?style=svg)](https://circleci.com/gh/milanito/withings-toolbox) [![Codacy Badge](https://api.codacy.com/project/badge/Grade/a3e7a9b1812848e39ab485b8d29c245f)](https://www.codacy.com/app/rondeau.matthieu.r/withings-toolbox?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=milanito/withings-toolbox&amp;utm_campaign=Badge_Grade) [![Codacy Badge](https://api.codacy.com/project/badge/Coverage/a3e7a9b1812848e39ab485b8d29c245f)](https://www.codacy.com/app/rondeau.matthieu.r/withings-toolbox?utm_source=github.com&utm_medium=referral&utm_content=milanito/withings-toolbox&utm_campaign=Badge_Coverage)

[![NPM](https://nodei.co/npm/withings-toolbox.png)](https://nodei.co/npm/withings-toolbox/)

This is a toolbox to request Withings API. I made this to fully comply with the Withings API documentation.

## Use it

The toolbox is used to generate the URLs described in the [Withings Documentation](https://developer.health.nokia.com/api)

### Step 1

The first step is used to get a oAuth "request token". Use it like this :

    import { generateWithingsRequestURL } from 'withings-toolbox';

    generateWithingsRequestURL(callbackURL, {
      oauthConsumerKey: 'Your withings API key',
      oauthConsumerSecret: 'Your withings API secret'
    })
    .then(url => console.log(url));

Where `callbackURL` is your application callback URL.

### Step 2

The second step is used to get a oAuth authorization URL. Use it like this :

    import { generateWithingsAuthorizeURL } from 'withings-toolbox';

    generateWithingsAuthorizeURL(token, secret, {
      oauthConsumerKey: 'Your withings API key',
      oauthConsumerSecret: 'Your withings API secret'
    })
    .then(url => console.log(url));

Where `token` is the Request token key and `secret` is Request token secret (as in the [Withings Documentation](https://developer.health.nokia.com/api))

### Step 3

The third step is used to get a access token URL. Use it like this :

    import { generateWithingsTokenURL } from 'withings-toolbox';

    generateWithingsTokenURL(token, secret, {
      oauthConsumerKey: 'Your withings API key',
      oauthConsumerSecret: 'Your withings API secret'
    })
    .then(url => console.log(url));

Where `token` is the Request token key and `secret` is Request token secret (as in the [Withings Documentation](https://developer.health.nokia.com/api))

### Step 4

The fourth step is used to get a measure URL. Use it like this :

- Activity

    import { generateWithingsMeasureActivityURL } from 'withings-toolbox';

    generateWithingsMeasureBodyURL(token, secret, {
      oauthConsumerKey: 'Your withings API key',
      oauthConsumerSecret: 'Your withings API secret'
    })
    .then(url => console.log(url));

Where `token` is the previously obtained token and `secret` is the previously obtained secret, from step 2 and 3 (as in the [Withings Documentation](https://developer.health.nokia.com/api))

- Body Measures

    import { generateWithingsMeasureBodyURL } from 'withings-toolbox';

    generateWithingsMeasureBodyURL(token, secret, {
      oauthConsumerKey: 'Your withings API key',
      oauthConsumerSecret: 'Your withings API secret'
    })
    .then(url => console.log(url));

Where `token` is the previously obtained token and `secret` is the previously obtained secret, from step 2 and 3 (as in the [Withings Documentation](https://developer.health.nokia.com/api))

- Sleep summary

    import { generateWithingsSleepSummaryURL } from 'withings-toolbox';

    generateWithingsSleepSummaryURL(token, secret, {
      oauthConsumerKey: 'Your withings API key',
      oauthConsumerSecret: 'Your withings API secret'
    })
    .then(url => console.log(url));

Where `token` is the previously obtained token and `secret` is the previously obtained secret, from step 2 and 3 (as in the [Withings Documentation](https://developer.health.nokia.com/api))
