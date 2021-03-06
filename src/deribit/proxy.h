/*
 * proxy.h
 *
 *  Created on: 21. 5. 2019
 *      Author: ondra
 */

#ifndef SRC_COINMATE_PROXY_H_
#define SRC_COINMATE_PROXY_H_
#include <curlpp/Easy.hpp>
#include <chrono>

#include <imtjson/value.h>
#include "config.h"

class Proxy {
public:

	Proxy(Config config);

	Config config;
	cURLpp::Easy curl_handle;

	///Send request
	/**
	 * @param method method
	 * @param params params (must be object)
	 * @param auth set true to include access token. set false for public request
	 * @return success response
	 * @exception std::runtime_error error response
	 */
	json::Value request(std::string_view method, json::Value params, bool auth);
	const std::string &getAccessToken();

	bool hasKey;
	bool debug = false;

	void setTimeDiff(std::intptr_t t);
	static std::uintptr_t now();



private:
	std::intptr_t time_diff = 0;
	std::string auth_token;
	std::chrono::system_clock::time_point auth_token_expire;
	std::size_t req_id = 1;

};



#endif /* SRC_COINMATE_PROXY_H_ */
