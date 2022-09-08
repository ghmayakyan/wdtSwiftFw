//
//  wdtWrapper.cpp
//  wdtFw
//
//  Created by Gevorg Hmayakyan on 08.09.22.
//


#include <string>
#include "wdtWrapper.hpp"
#include <wdt/Receiver.h>
#include <wdt/Wdt.h>
#include <wdt/WdtResourceController.h>
#include <wdt/WdtTransferRequest.h>

#include <folly/String.h>
#include <gflags/gflags.h>
#include <glog/logging.h>
#include <signal.h>
#include <chrono>
#include <fstream>
#include <future>
#include <iostream>
#include <thread>

int initializeWdt(const char* url, const char *dir) {
    facebook::wdt::Wdt &wdt = facebook::wdt::Wdt::initializeWdt("wdtWrapper");
    std::unique_ptr<facebook::wdt::WdtTransferRequest> reqPtr =
    std::make_unique<facebook::wdt::WdtTransferRequest>(url);
//    if (reqPtr->errorCode != facebook::wdt::OK) {
//          WLOG(ERROR) << "Invalid url \"" << connectUrl
//                      << "\" : " << errorCodeToStr(reqPtr->errorCode);
//        return google::ERROR;
//    }
//
    reqPtr->directory = dir;
    facebook::wdt::WdtTransferRequest &req = *reqPtr;
    int retCode = wdt.wdtSend(req);
    return retCode;
//    return 0;
}
