#ifndef NVME_PRINT_H
#define NVME_PRINT_H

#include "nvme.h"
#include "util/json.h"
#include <inttypes.h>

void d(unsigned char *buf, int len, int width, int group);
void d_raw(unsigned char *buf, unsigned len);
uint64_t int48_to_long(__u8 *data);

void nvme_show_relatives(const char *name);

void __nvme_show_id_ctrl(struct nvme_id_ctrl *ctrl, unsigned int mode,
	void (*vendor_show)(__u8 *vs, struct json_object *root));
void nvme_show_id_ctrl(struct nvme_id_ctrl *ctrl, unsigned int mode);
void nvme_show_id_ns(struct nvme_id_ns *ns, unsigned int nsid,
	enum nvme_print_flags flags);
void nvme_show_resv_report(struct nvme_reservation_status *status, int bytes, __u32 cdw11,
	enum nvme_print_flags flags);
void nvme_show_lba_range(struct nvme_lba_range_type *lbrt, int nr_ranges);
void nvme_show_error_log(struct nvme_error_log_page *err_log, int entries,
	const char *devname, enum nvme_print_flags flags);
void nvme_show_smart_log(struct nvme_smart_log *smart, unsigned int nsid,
	const char *devname, enum nvme_print_flags flags);
void nvme_show_ana_log(struct nvme_ana_log *ana_log, const char *devname,
	enum nvme_print_flags flags, size_t len);
void nvme_show_self_test_log(struct nvme_self_test_log *self_test, const char *devname,
	enum nvme_print_flags flags);
void nvme_show_fw_log(struct nvme_firmware_slot *fw_log, const char *devname,
	enum nvme_print_flags flags);
void nvme_show_effects_log(struct nvme_cmd_effects_log *effects, unsigned int flags);
void nvme_show_changed_ns_list_log(struct nvme_ns_list *log,
	const char *devname, enum nvme_print_flags flags);
void nvme_show_endurance_log(struct nvme_endurance_group_log *endurance_log,
	__u16 group_id, const char *devname, enum nvme_print_flags flags);
void nvme_show_sanitize_log(struct nvme_sanitize_log_page *sanitize,
	const char *devname, enum nvme_print_flags flags);
void nvme_show_ctrl_registers(void *bar, bool fabrics, enum nvme_print_flags flags);
void nvme_show_single_property(int offset, uint64_t prop, int human);
void nvme_show_id_ns_descs(void *data, unsigned nsid, enum nvme_print_flags flags);
void nvme_show_lba_status(struct nvme_lba_status *list, unsigned long len,
	enum nvme_print_flags flags);
void nvme_show_list_items(struct nvme_root *r, enum nvme_print_flags flags);
void nvme_show_id_nvmset(struct nvme_id_nvmset_list *nvmset, unsigned nvmset_id,
	enum nvme_print_flags flags);
void nvme_show_list_secondary_ctrl(const struct nvme_secondary_ctrl_list *sc_list,
	__u32 count, enum nvme_print_flags flags);
void nvme_show_id_ns_granularity_list(const struct nvme_id_ns_granularity_list *glist,
	enum nvme_print_flags flags);
void nvme_show_id_uuid_list(const struct nvme_id_uuid_list *uuid_list,
	enum nvme_print_flags flags);

void nvme_feature_show_fields(__u32 fid, unsigned int result, unsigned char *buf);
void nvme_directive_show(__u8 type, __u8 oper, __u16 spec, __u32 nsid, __u32 result,
	void *buf, __u32 len, enum nvme_print_flags flags);
void nvme_show_select_result(__u32 result);

const char *nvme_status_to_string(__u32 status);
const char *nvme_select_to_string(int sel);
const char *nvme_feature_to_string(int feature);
const char *nvme_register_to_string(int reg);

#endif
