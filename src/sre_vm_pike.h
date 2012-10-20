
/*
 * Copyright 2012 Yichun "agentzh" Zhang
 * Copyright 2007-2009 Russ Cox.  All Rights Reserved.
 * Use of this source code is governed by a BSD-style
 * license that can be found in the LICENSE file.
 */


#ifndef _SRE_VM_PIKE_H_INCLUDED_
#define _SRE_VM_PIKE_H_INCLUDED_


#include <sre_core.h>
#include <sre_vm_bytecode.h>


int sre_vm_pike_exec(sre_pool_t *pool, sre_program_t *prog, u_char *input,
    int *ovector, unsigned ovecsize);


#endif /* _SRE_VM_PIKE_H_INCLUDED_ */
