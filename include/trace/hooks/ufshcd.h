/* SPDX-License-Identifier: GPL-2.0 */
#undef TRACE_SYSTEM
#define TRACE_SYSTEM ufshcd
#define TRACE_INCLUDE_PATH trace/hooks
#if !defined(_TRACE_HOOK_UFSHCD_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_HOOK_UFSHCD_H
#include <linux/tracepoint.h>
#include <trace/hooks/vendor_hooks.h>
/*
 * Following tracepoints are not exported in tracefs and provide a
 * mechanism for vendor modules to hook and extend functionality
 */
struct ufs_hba;
struct request;
struct ufshcd_lrb;
DECLARE_HOOK(android_vh_ufs_prepare_command,
	TP_PROTO(struct ufs_hba *hba, struct request *rq,
		 struct ufshcd_lrb *lrbp, int *err),
	TP_ARGS(hba, rq, lrbp, err));

DECLARE_HOOK(android_vh_ufs_update_sysfs,
	TP_PROTO(struct ufs_hba *hba),
	TP_ARGS(hba));

DECLARE_HOOK(android_vh_ufs_send_command,
	TP_PROTO(struct ufs_hba *hba, struct ufshcd_lrb *lrbp),
	TP_ARGS(hba, lrbp));

DECLARE_HOOK(android_vh_ufs_compl_command,
	TP_PROTO(struct ufs_hba *hba, struct ufshcd_lrb *lrbp),
	TP_ARGS(hba, lrbp));

#endif /* _TRACE_HOOK_UFSHCD_H */
/* This part must be outside protection */
#include <trace/define_trace.h>
