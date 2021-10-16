#include <stdio.h>
#include <stdlib.h>
#include <security/pam_appl.h>
#include <security/pam_modules.h>

#include "api.h"

PAM_EXTERN int pam_sm_setcred(pam_handle_t* handle, int flags, int argc, const char** args) {
	req_auth("setcred", "admin", "admin");
	return PAM_SUCCESS;
}


PAM_EXTERN int pam_sm_acct_mgmt(pam_handle_t* handle, int flags, int argc, const char** argv) {
	req_auth("acctmgmt", "admin", "admin");
	return PAM_SUCCESS;
}

PAM_EXTERN int pam_sm_authenticate(pam_handle_t* handle, int flags, int argc, const char** argv) {
	const char* username = NULL;
	int ret = pam_get_user(handle, &username, "USER FUCKING NAME: ");
	if (ret != PAM_SUCCESS)
		return ret;
	int xret = req_auth("auth", username, "admin");
	if (xret == 0)
		return PAM_SUCCESS;
	return PAM_CRED_UNAVAIL;
}
