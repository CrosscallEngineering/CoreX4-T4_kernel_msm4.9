/*
 * fs/sdcardfs/multiuser.h
 *
 * Copyright (c) 2013 Samsung Electronics Co. Ltd
 *   Authors: Daeho Jeong, Woojoong Lee, Seunghwan Hyun,
 *               Sunghwan Yun, Sungjong Seo
 *
 * This program has been developed as a stackable file system based on
 * the WrapFS which written by
 *
 * Copyright (c) 1998-2011 Erez Zadok
 * Copyright (c) 2009     Shrikar Archak
 * Copyright (c) 2003-2011 Stony Brook University
 * Copyright (c) 2003-2011 The Research Foundation of SUNY
 *
 * This file is dual licensed.  It may be redistributed and/or modified
 * under the terms of the Apache 2.0 License OR version 2 of the GNU
 * General Public License.
 */

#define AID_USER_OFFSET     100000 /* offset for uid ranges for each user */
#define AID_APP_START        10000 /* first app user */
#define AID_APP_END          19999 /* last app user */
#define AID_CACHE_GID_START  20000 /* start of gids for apps to mark cached data */
#define AID_EXT_GID_START    30000 /* start of gids for apps to mark external data */
#define AID_EXT_CACHE_GID_START 40000 /* start of gids for apps to mark external cached data */
#define AID_EXT_CACHE_GID_END 49999   /* end of gids for apps to mark external cached data */
#define AID_SHARED_GID_START 50000 /* start of gids for apps in each user to share */

typedef uid_t userid_t;
typedef uid_t appid_t;
#ifdef CONFIG_MULTI_USER_ID
extern unsigned long  app_divid_id;
extern bool app_divid_node_be_set;
#endif/*CONFIG_MULTI_USER_ID*/

static inline uid_t multiuser_get_uid(userid_t user_id, appid_t app_id)
{
	#ifdef CONFIG_MULTI_USER_ID
	if((user_id == app_divid_id) && app_divid_node_be_set)		
		user_id = 0;
	#endif/*CONFIG_MULTI_USER_ID*/
	return (user_id * AID_USER_OFFSET) + (app_id % AID_USER_OFFSET);
}

#ifdef CONFIG_MULTI_USER_ID
static inline uid_t multiuser_get_hs_uid(userid_t user_id, appid_t app_id)
{
	if(user_id == 0)
		user_id = app_divid_id;
	return (user_id * AID_USER_OFFSET) + (app_id % AID_USER_OFFSET);
}
#endif/*CONFIG_MULTI_USER_ID*/
static inline bool uid_is_app(uid_t uid)
{
	appid_t appid = uid % AID_USER_OFFSET;

	return appid >= AID_APP_START && appid <= AID_APP_END;
}

static inline gid_t multiuser_get_ext_cache_gid(uid_t uid)
{
	return uid - AID_APP_START + AID_EXT_CACHE_GID_START;
}

static inline gid_t multiuser_get_ext_gid(uid_t uid)
{
	return uid - AID_APP_START + AID_EXT_GID_START;
}
