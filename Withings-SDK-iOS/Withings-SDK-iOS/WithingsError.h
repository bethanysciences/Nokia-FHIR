//
// WithingsError.h
// Withings-SDK-iOS
// 
// Copyright (c) 2016 jdrevet
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#import <Foundation/Foundation.h>

/**
 * Error generated by the SDK.
 * The domain is WITHINGS_DOMAIN_ERROR.
 * The error codes are defined in WithingsErrorCode enum.
 * The error returned by the Withings server are the code WithingsErrorServer (= 1). The server error code and message can be retrieved in the additional property serverErrorCode and serverErrorMessage.
 */
@interface WithingsError : NSError

/**
 * The domain of the WithingsError
 */
extern NSString * const WITHINGS_DOMAIN_ERROR;

/**
 * Error codes returned by the SDK.
 */
typedef NS_ENUM(NSInteger, WithingsErrorCode) {
    /** Unknown error */
    WithingsErrorUnknown = 0,
    /** Error returned by the server */
    WithingsErrorServer = 1,
    /** Error during OAuth authorization process */
    WithingsErrorOAuth = 2,
    /** Authorization cannot be retrieved for the user. Use the method requestAccessAuthorizationWithCallbackScheme:presenterViewController:completion: of the WithingsAPI singleton to request authorization */
    WithingsErrorNoUserAuthorization = 3,
    /** An HTTP error occured during API call */
    WithingsErrorHTTP = 4,
    /** The response received from the server cannot be parsed */
    WithingsErrorResponseParsing = 5
};

/**
 * Error codes returned by the server. 
 * All the server errors are returned with the error code WithingsErrorServer (= 1). Server error code can be retrieved in the additional property serverErrorCode.
 */
typedef NS_ENUM(NSInteger, WithingsServerErrorCode) {
    /** The userid provided is absent, or incorrect */
    WithingsServerErrorWrongUserId = 247,
    /** The provided userid and/or Oauth credentials do not match */
    WithingsServerErrorWrongCredentials = 250,
    /** No such subscription was found */
    WithingsServerErrorSubscriptionNotFound = 286,
    /** The callback URL is either absent or incorrect */
    WithingsServerErrorWrongCallbackURL = 293,
    /** No such subscription could be deleted */
    WithingsServerErrorCannotDeleteSubscription = 294,
    /** The comment is either absent or incorrect */
    WithingsServerErrorWrongComment = 304,
    /** Too many notifications are already set */
    WithingsServerErrorTooManyNotifSet = 305,
    /** The user is deactivated */
    WithingsServerErrorUserDeactivated = 328,
    /** The signature (using Oauth) is invalid */
    WithingsServerErrorWrongOAuthSignature = 342,
    /** Notification Callback Url does not exist */
    WithingsServerErrorWrongNotifCallbackURL = 343,
    /** Too Many Request */
    WithingsServerErrorTooManyRequest = 601,
    /** Wrong action or wrong webservice */
    WithingsServerErrorWrongAction = 2554,
    /** An unknown error occurred */
    WithingsServerErrorUnknown = 2555,
    /** Service is not defined */
    WithingsServerErrorServiceUndefined = 2556
};

/**
 * The error code returned by the server for the server error (code = WithingsErrorServer = 1).
 */
@property (readonly, nonatomic) WithingsServerErrorCode serverErrorCode;
/**
 * The error message returned by the server for the server error (code = WithingsErrorServer = 1).
 */
@property (readonly, nonatomic) NSString *serverErrorMessage;

/**
 * Creates and returns a WithingsError with the specified code and message
 *
 * @param code The error code
 * @param message The error message which will be set as localized description
 * @return The WithingsError initialized with the given attributes
 */
+ (instancetype)errorWithCode:(WithingsErrorCode)code message:(NSString*)message;
/**
 * Creates and returns a WithingsError
 *
 * @param code The error code
 * @param userInfo The userInfo dictionary for the error
 * @return The WithingsError initialized with the given attributes
 */
+ (instancetype)errorWithCode:(WithingsErrorCode)code userInfo:(NSDictionary*)userInfo;
/**
 * Creates and returns a WithingsError which represents a server error. 
 * The error code will be WithingsErrorServer (= 1).
 * The error info returned by the server can be retrieved in additional properties serverErrorCode and serverErrorMessage.
 *
 * @param serverErrorCode The error code returned by the server
 * @param serverErrorMessage The error message returned by the server
 * @return The WithingsError initialized with the given attributes
 */
+ (instancetype)serverErrorWithCode:(WithingsServerErrorCode)serverErrorCode message:(NSString*)serverErrorMessage;

@end