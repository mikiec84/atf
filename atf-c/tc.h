/*
 * Automated Testing Framework (atf)
 *
 * Copyright (c) 2008 The NetBSD Foundation, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this
 *    software must display the following acknowledgement:
 *        This product includes software developed by the NetBSD
 *        Foundation, Inc. and its contributors.
 * 4. Neither the name of The NetBSD Foundation nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND
 * CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
 * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#if !defined(ATF_C_TC_H)
#define ATF_C_TC_H

#include <stddef.h>
#include <unistd.h>

#include <atf-c/dynstr.h>
#include <atf-c/object.h>

/* ---------------------------------------------------------------------
 * The "atf_tcr" type.
 * --------------------------------------------------------------------- */

extern const int atf_tcr_passed;
extern const int atf_tcr_failed;
extern const int atf_tcr_skipped;

struct atf_tcr {
    atf_object_t m_object;

    int m_status;
    atf_dynstr_t m_reason;
};
typedef struct atf_tcr atf_tcr_t;

void atf_tcr_init(atf_tcr_t *, int);
int atf_tcr_init_reason(atf_tcr_t *, int, const char *, ...);
void atf_tcr_fini(atf_tcr_t *);

int atf_tcr_get_status(const atf_tcr_t *);
const char *atf_tcr_get_reason(const atf_tcr_t *);

/* ---------------------------------------------------------------------
 * The "atf_tc" type.
 * --------------------------------------------------------------------- */

struct atf_tc {
    atf_object_t m_object;

    const char *m_ident;

    const char *m_workdir;

    void (*m_head)(struct atf_tc *);
    void (*m_body)(const struct atf_tc *);
    void (*m_cleanup)(const struct atf_tc *);
};
typedef struct atf_tc atf_tc_t;

void atf_tc_init(atf_tc_t *);
void atf_tc_fini(atf_tc_t *);

atf_tcr_t atf_tc_run(atf_tc_t *);

void atf_tc_fail(const char *, ...);
void atf_tc_pass(void);
void atf_tc_skip(const char *, ...);

void atf_tc_set_var(const char *, const char *, ...);

#endif /* ATF_C_TC_H */
