#pragma once

#include <cstddef>
#include <string>

#ifndef ARBITER_IS_AMALGAMATION

#include <arbiter/util/types.hpp>

#endif

class curl_slist;

#ifdef ARBITER_CUSTOM_NAMESPACE
namespace ARBITER_CUSTOM_NAMESPACE
{
#endif

namespace arbiter
{
namespace http
{

/** @cond arbiter_internal */

class Pool;

class Curl
{
    friend class Pool;

public:
    ~Curl();

    http::Response get(
            std::string path,
            Headers headers,
            Query query,
            std::size_t reserve);

    http::Response head(std::string path, Headers headers, Query query);

    http::Response put(
            std::string path,
            const std::vector<char>& data,
            Headers headers,
            Query query);

    http::Response post(
            std::string path,
            const std::vector<char>& data,
            Headers headers,
            Query query);

private:
    Curl(bool verbose, std::size_t timeout);

    void init(std::string path, const Headers& headers, const Query& query);

    Curl(const Curl&);
    Curl& operator=(const Curl&);

    void* m_curl;
    curl_slist* m_headers;
    const bool m_verbose;
    const long m_timeout;

    std::vector<char> m_data;
};

/** @endcond */

} // namespace http
} // namespace arbiter

#ifdef ARBITER_CUSTOM_NAMESPACE
}
#endif

