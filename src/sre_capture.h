
/*
 * Copyright 2012 Yichun "agentzh" Zhang
 * Copyright 2007-2009 Russ Cox.  All Rights Reserved.
 * Use of this source code is governed by a BSD-style
 * license that can be found in the LICENSE file.
 */


#ifndef _SRE_CAPTURE_H_INCLUDED_
#define _SRE_CAPTURE_H_INCLUDED_


#include <sre_core.h>
#include <sre_palloc.h>


#define sre_capture_decr_ref(cap, freecaps)                                  \
    if (--(cap)->ref == 0) {                                                 \
        (cap)->next = (freecaps);                                            \
        (freecaps) = (cap);                                                 \
    }


typedef struct sre_capture_s  sre_capture_t;

struct sre_capture_s {
    unsigned         ref;  /* reference count */
    unsigned         ovecsize;
    int             *vector;
    sre_capture_t   *next;
};


sre_capture_t *sre_capture_create(sre_pool_t *pool, unsigned ovecsize,
    unsigned clear);
sre_capture_t *sre_capture_update(sre_pool_t *pool, sre_capture_t *cap,
    unsigned group, int pos, sre_capture_t *freecap);
void sre_capture_destroy(sre_pool_t *pool, sre_capture_t *cap);


#endif /* _SRE_CAPTURE_H_INCLUDED_ */
