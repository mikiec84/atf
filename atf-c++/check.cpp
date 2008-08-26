//
// Automated Testing Framework (atf)
//
// Copyright (c) 2007, 2008 The NetBSD Foundation, Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
// 1. Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND
// CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,
// INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
// IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
// GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
// IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
// OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
// IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//

#include "atf-c++/check.hpp"
#include "atf-c++/exceptions.hpp"

namespace impl = atf::check;
#define IMPL_NAME "atf::check"

// ------------------------------------------------------------------------
// The "check_result" class.
// ------------------------------------------------------------------------

impl::check_result::check_result(void)
{
}

impl::check_result::~check_result()
{
    atf_check_result_fini(&m_result);
}

int
impl::check_result::status()
    const
{
    return atf_check_result_status(&m_result);
}

const atf::fs::path
impl::check_result::stdout_path()
    const
{
    return atf_check_result_stdout(&m_result);
}

const atf::fs::path
impl::check_result::stderr_path()
        const
    {
    return atf_check_result_stderr(&m_result);
}

// ------------------------------------------------------------------------
// Free functions.
// ------------------------------------------------------------------------

impl::check_result
impl::exec(char * const *argv)
{
    impl::check_result res;

    atf_error_t err = atf_check_exec(argv, &res.m_result);
    if (atf_is_error(err))
        throw_atf_error(err);

    return res;
}
