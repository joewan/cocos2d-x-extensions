
#ifndef __EXTENSIONS_CCNETWORK_H_
#define __EXTENSIONS_CCNETWORK_H_

#include "CCHttpRequest.h"
#include "CCHttpRequestDelegate.h"

namespace extensions {
    
    typedef enum {
        CCNetworkStatusNotReachable = 0,
        CCNetworkStatusReachableViaWiFi,
        CCNetworkStatusReachableViaWWAN
    } CCNetworkStatus;
    
        
    class CCNetwork
    {
    public:
#pragma mark -
#pragma mark reachability
        
        /** @brief Checks whether a local wifi connection is available */
        static bool isLocalWiFiAvailable(void);
        
        /** @brief Checks whether the default route is available */
        static bool isInternetConnectionAvailable(void);
        
        /** @brief Checks the reachability of a particular host name */
        static bool isHostNameReachable(const char* hostName);
        
        /** @brief Checks Internet connection reachability status */
        static CCNetworkStatus getInternetConnectionStatus(void);
        
#pragma mark -
#pragma mark HTTP
        
        static CCHttpRequest* httpRequest(CCHttpRequestDelegate* delegate,
                                          const char* url,
                                          CCHttpRequestMethod method);
        
    private:
        CCNetwork(void) {}
    };
    
}

#endif // __EXTENSIONS_CCNETWORK_H_
