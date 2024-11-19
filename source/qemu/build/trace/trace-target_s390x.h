/* This file is autogenerated by tracetool, do not edit. */

#ifndef TRACE_TARGET_S390X_GENERATED_TRACERS_H
#define TRACE_TARGET_S390X_GENERATED_TRACERS_H

#include "trace/control.h"

extern TraceEvent _TRACE_IOINST_EVENT;
extern TraceEvent _TRACE_IOINST_SCH_ID_EVENT;
extern TraceEvent _TRACE_IOINST_CHP_ID_EVENT;
extern TraceEvent _TRACE_IOINST_CHSC_CMD_EVENT;
extern TraceEvent _TRACE_CPU_SET_STATE_EVENT;
extern TraceEvent _TRACE_CPU_HALT_EVENT;
extern TraceEvent _TRACE_CPU_UNHALT_EVENT;
extern TraceEvent _TRACE_SIGP_FINISHED_EVENT;
extern uint16_t _TRACE_IOINST_DSTATE;
extern uint16_t _TRACE_IOINST_SCH_ID_DSTATE;
extern uint16_t _TRACE_IOINST_CHP_ID_DSTATE;
extern uint16_t _TRACE_IOINST_CHSC_CMD_DSTATE;
extern uint16_t _TRACE_CPU_SET_STATE_DSTATE;
extern uint16_t _TRACE_CPU_HALT_DSTATE;
extern uint16_t _TRACE_CPU_UNHALT_DSTATE;
extern uint16_t _TRACE_SIGP_FINISHED_DSTATE;
#define TRACE_IOINST_ENABLED 1
#define TRACE_IOINST_SCH_ID_ENABLED 1
#define TRACE_IOINST_CHP_ID_ENABLED 1
#define TRACE_IOINST_CHSC_CMD_ENABLED 1
#define TRACE_CPU_SET_STATE_ENABLED 1
#define TRACE_CPU_HALT_ENABLED 1
#define TRACE_CPU_UNHALT_ENABLED 1
#define TRACE_SIGP_FINISHED_ENABLED 1
#include "qemu/log-for-trace.h"
#include "qemu/error-report.h"


#define TRACE_IOINST_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_IOINST) || \
    false)

static inline void _nocheck__trace_ioinst(const char * insn)
{
    if (trace_event_get_state(TRACE_IOINST) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 4 "../target/s390x/trace-events"
            qemu_log("%d@%zu.%06zu:ioinst " "IOINST: %s" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , insn);
#line 52 "trace/trace-target_s390x.h"
        } else {
#line 4 "../target/s390x/trace-events"
            qemu_log("ioinst " "IOINST: %s" "\n", insn);
#line 56 "trace/trace-target_s390x.h"
        }
    }
}

static inline void trace_ioinst(const char * insn)
{
    if (true) {
        _nocheck__trace_ioinst(insn);
    }
}

#define TRACE_IOINST_SCH_ID_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_IOINST_SCH_ID) || \
    false)

static inline void _nocheck__trace_ioinst_sch_id(const char * insn, int cssid, int ssid, int schid)
{
    if (trace_event_get_state(TRACE_IOINST_SCH_ID) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 5 "../target/s390x/trace-events"
            qemu_log("%d@%zu.%06zu:ioinst_sch_id " "IOINST: %s (%x.%x.%04x)" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , insn, cssid, ssid, schid);
#line 83 "trace/trace-target_s390x.h"
        } else {
#line 5 "../target/s390x/trace-events"
            qemu_log("ioinst_sch_id " "IOINST: %s (%x.%x.%04x)" "\n", insn, cssid, ssid, schid);
#line 87 "trace/trace-target_s390x.h"
        }
    }
}

static inline void trace_ioinst_sch_id(const char * insn, int cssid, int ssid, int schid)
{
    if (true) {
        _nocheck__trace_ioinst_sch_id(insn, cssid, ssid, schid);
    }
}

#define TRACE_IOINST_CHP_ID_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_IOINST_CHP_ID) || \
    false)

static inline void _nocheck__trace_ioinst_chp_id(const char * insn, int cssid, int chpid)
{
    if (trace_event_get_state(TRACE_IOINST_CHP_ID) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 6 "../target/s390x/trace-events"
            qemu_log("%d@%zu.%06zu:ioinst_chp_id " "IOINST: %s (%x.%02x)" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , insn, cssid, chpid);
#line 114 "trace/trace-target_s390x.h"
        } else {
#line 6 "../target/s390x/trace-events"
            qemu_log("ioinst_chp_id " "IOINST: %s (%x.%02x)" "\n", insn, cssid, chpid);
#line 118 "trace/trace-target_s390x.h"
        }
    }
}

static inline void trace_ioinst_chp_id(const char * insn, int cssid, int chpid)
{
    if (true) {
        _nocheck__trace_ioinst_chp_id(insn, cssid, chpid);
    }
}

#define TRACE_IOINST_CHSC_CMD_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_IOINST_CHSC_CMD) || \
    false)

static inline void _nocheck__trace_ioinst_chsc_cmd(uint16_t cmd, uint16_t len)
{
    if (trace_event_get_state(TRACE_IOINST_CHSC_CMD) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 7 "../target/s390x/trace-events"
            qemu_log("%d@%zu.%06zu:ioinst_chsc_cmd " "IOINST: chsc command 0x%04x, len 0x%04x" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , cmd, len);
#line 145 "trace/trace-target_s390x.h"
        } else {
#line 7 "../target/s390x/trace-events"
            qemu_log("ioinst_chsc_cmd " "IOINST: chsc command 0x%04x, len 0x%04x" "\n", cmd, len);
#line 149 "trace/trace-target_s390x.h"
        }
    }
}

static inline void trace_ioinst_chsc_cmd(uint16_t cmd, uint16_t len)
{
    if (true) {
        _nocheck__trace_ioinst_chsc_cmd(cmd, len);
    }
}

#define TRACE_CPU_SET_STATE_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_CPU_SET_STATE) || \
    false)

static inline void _nocheck__trace_cpu_set_state(int cpu_index, uint8_t state)
{
    if (trace_event_get_state(TRACE_CPU_SET_STATE) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 10 "../target/s390x/trace-events"
            qemu_log("%d@%zu.%06zu:cpu_set_state " "setting cpu %d state to %" PRIu8 "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , cpu_index, state);
#line 176 "trace/trace-target_s390x.h"
        } else {
#line 10 "../target/s390x/trace-events"
            qemu_log("cpu_set_state " "setting cpu %d state to %" PRIu8 "\n", cpu_index, state);
#line 180 "trace/trace-target_s390x.h"
        }
    }
}

static inline void trace_cpu_set_state(int cpu_index, uint8_t state)
{
    if (true) {
        _nocheck__trace_cpu_set_state(cpu_index, state);
    }
}

#define TRACE_CPU_HALT_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_CPU_HALT) || \
    false)

static inline void _nocheck__trace_cpu_halt(int cpu_index)
{
    if (trace_event_get_state(TRACE_CPU_HALT) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 11 "../target/s390x/trace-events"
            qemu_log("%d@%zu.%06zu:cpu_halt " "halting cpu %d" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , cpu_index);
#line 207 "trace/trace-target_s390x.h"
        } else {
#line 11 "../target/s390x/trace-events"
            qemu_log("cpu_halt " "halting cpu %d" "\n", cpu_index);
#line 211 "trace/trace-target_s390x.h"
        }
    }
}

static inline void trace_cpu_halt(int cpu_index)
{
    if (true) {
        _nocheck__trace_cpu_halt(cpu_index);
    }
}

#define TRACE_CPU_UNHALT_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_CPU_UNHALT) || \
    false)

static inline void _nocheck__trace_cpu_unhalt(int cpu_index)
{
    if (trace_event_get_state(TRACE_CPU_UNHALT) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 12 "../target/s390x/trace-events"
            qemu_log("%d@%zu.%06zu:cpu_unhalt " "unhalting cpu %d" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , cpu_index);
#line 238 "trace/trace-target_s390x.h"
        } else {
#line 12 "../target/s390x/trace-events"
            qemu_log("cpu_unhalt " "unhalting cpu %d" "\n", cpu_index);
#line 242 "trace/trace-target_s390x.h"
        }
    }
}

static inline void trace_cpu_unhalt(int cpu_index)
{
    if (true) {
        _nocheck__trace_cpu_unhalt(cpu_index);
    }
}

#define TRACE_SIGP_FINISHED_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_SIGP_FINISHED) || \
    false)

static inline void _nocheck__trace_sigp_finished(uint8_t order, int cpu_index, int dst_index, int cc)
{
    if (trace_event_get_state(TRACE_SIGP_FINISHED) && qemu_loglevel_mask(LOG_TRACE)) {
        if (message_with_timestamp) {
            struct timeval _now;
            gettimeofday(&_now, NULL);
#line 15 "../target/s390x/trace-events"
            qemu_log("%d@%zu.%06zu:sigp_finished " "SIGP: Finished order %u on cpu %d -> cpu %d with cc=%d" "\n",
                     qemu_get_thread_id(),
                     (size_t)_now.tv_sec, (size_t)_now.tv_usec
                     , order, cpu_index, dst_index, cc);
#line 269 "trace/trace-target_s390x.h"
        } else {
#line 15 "../target/s390x/trace-events"
            qemu_log("sigp_finished " "SIGP: Finished order %u on cpu %d -> cpu %d with cc=%d" "\n", order, cpu_index, dst_index, cc);
#line 273 "trace/trace-target_s390x.h"
        }
    }
}

static inline void trace_sigp_finished(uint8_t order, int cpu_index, int dst_index, int cc)
{
    if (true) {
        _nocheck__trace_sigp_finished(order, cpu_index, dst_index, cc);
    }
}
#endif /* TRACE_TARGET_S390X_GENERATED_TRACERS_H */
