/* AUTOMATICALLY GENERATED by qapi-gen.py DO NOT MODIFY */

/*
 * Schema-defined QAPI types
 *
 * Copyright IBM, Corp. 2011
 * Copyright (c) 2013-2018 Red Hat Inc.
 *
 * This work is licensed under the terms of the GNU LGPL, version 2.1 or later.
 * See the COPYING.LIB file in the top-level directory.
 */

#include "qemu/osdep.h"
#include "qapi/dealloc-visitor.h"
#include "qapi-types-vfio.h"
#include "qapi-visit-vfio.h"

const QEnumLookup QapiVfioMigrationState_lookup = {
    .array = (const char *const[]) {
        [QAPI_VFIO_MIGRATION_STATE_STOP] = "stop",
        [QAPI_VFIO_MIGRATION_STATE_RUNNING] = "running",
        [QAPI_VFIO_MIGRATION_STATE_STOP_COPY] = "stop-copy",
        [QAPI_VFIO_MIGRATION_STATE_RESUMING] = "resuming",
        [QAPI_VFIO_MIGRATION_STATE_RUNNING_P2P] = "running-p2p",
        [QAPI_VFIO_MIGRATION_STATE_PRE_COPY] = "pre-copy",
        [QAPI_VFIO_MIGRATION_STATE_PRE_COPY_P2P] = "pre-copy-p2p",
    },
    .size = QAPI_VFIO_MIGRATION_STATE__MAX
};

/* Dummy declaration to prevent empty .o file */
char qapi_dummy_qapi_types_vfio_c;
