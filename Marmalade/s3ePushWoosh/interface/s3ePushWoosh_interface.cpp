/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */

#include "s3eExt.h"
#include "IwDebug.h"
#include "s3eDevice.h"


#include "s3ePushWoosh.h"


#ifndef S3E_EXT_SKIP_LOADER_CALL_LOCK
// For MIPs (and WP8) platform we do not have asm code for stack switching
// implemented. So we make LoaderCallStart call manually to set GlobalLock
#if defined __mips || defined S3E_ANDROID_X86 || (defined(WINAPI_FAMILY) && (WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP))
#define LOADER_CALL_LOCK
#endif
#endif

/**
 * Definitions for functions types passed to/from s3eExt interface
 */
typedef  s3eResult(*s3ePushWooshRegister_t)(s3ePushWooshCallback cbid, s3eCallback fn, void* userData);
typedef  s3eResult(*s3ePushWooshUnRegister_t)(s3ePushWooshCallback cbid, s3eCallback fn);
typedef    s3eBool(*s3ePushWooshNotificationsAvailable_t)();
typedef  s3eResult(*s3ePushWooshNotificationRegister_t)();
typedef     char *(*s3ePushWooshGetToken_t)();
typedef  s3eResult(*s3ePushWooshNotificationUnRegister_t)();
typedef  s3eResult(*s3ePushWooshNotificationSetIntTag_t)(const char * tagName, int tagValue);
typedef  s3eResult(*s3ePushWooshNotificationSetStringTag_t)(const char * tagName, const char * tagValue);
typedef  s3eResult(*s3ePushWooshNotificationSetBadgeNumber_t)(int badgeValue);
typedef  s3eResult(*s3ePushWooshClearLocalNotifications_t)();
typedef  s3eResult(*s3ePushWooshStartLocationTracking_t)();
typedef  s3eResult(*s3ePushWooshStopLocationTracking_t)();
typedef  s3eResult(*s3ePushWooshScheduleLocalNotification_t)(const char * message, int seconds, const char * userdata);
typedef  s3eResult(*s3ePushWooshSetAndroidNotificationMultiMode_t)(bool enable);

/**
 * struct that gets filled in by s3ePushWooshRegister
 */
typedef struct s3ePushWooshFuncs
{
    s3ePushWooshRegister_t m_s3ePushWooshRegister;
    s3ePushWooshUnRegister_t m_s3ePushWooshUnRegister;
    s3ePushWooshNotificationsAvailable_t m_s3ePushWooshNotificationsAvailable;
    s3ePushWooshNotificationRegister_t m_s3ePushWooshNotificationRegister;
    s3ePushWooshGetToken_t m_s3ePushWooshGetToken;
    s3ePushWooshNotificationUnRegister_t m_s3ePushWooshNotificationUnRegister;
    s3ePushWooshNotificationSetIntTag_t m_s3ePushWooshNotificationSetIntTag;
    s3ePushWooshNotificationSetStringTag_t m_s3ePushWooshNotificationSetStringTag;
    s3ePushWooshNotificationSetBadgeNumber_t m_s3ePushWooshNotificationSetBadgeNumber;
    s3ePushWooshClearLocalNotifications_t m_s3ePushWooshClearLocalNotifications;
    s3ePushWooshStartLocationTracking_t m_s3ePushWooshStartLocationTracking;
    s3ePushWooshStopLocationTracking_t m_s3ePushWooshStopLocationTracking;
    s3ePushWooshScheduleLocalNotification_t m_s3ePushWooshScheduleLocalNotification;
    s3ePushWooshSetAndroidNotificationMultiMode_t m_s3ePushWooshSetAndroidNotificationMultiMode;
} s3ePushWooshFuncs;

static s3ePushWooshFuncs g_Ext;
static bool g_GotExt = false;
static bool g_TriedExt = false;
static bool g_TriedNoMsgExt = false;

static bool _extLoad()
{
    if (!g_GotExt && !g_TriedExt)
    {
        s3eResult res = s3eExtGetHash(0xffcac5e0, &g_Ext, sizeof(g_Ext));
        if (res == S3E_RESULT_SUCCESS)
            g_GotExt = true;
        else
            s3eDebugAssertShow(S3E_MESSAGE_CONTINUE_STOP_IGNORE,                 "error loading extension: s3ePushWoosh");

        g_TriedExt = true;
        g_TriedNoMsgExt = true;
    }

    return g_GotExt;
}

static bool _extLoadNoMsg()
{
    if (!g_GotExt && !g_TriedNoMsgExt)
    {
        s3eResult res = s3eExtGetHash(0xffcac5e0, &g_Ext, sizeof(g_Ext));
        if (res == S3E_RESULT_SUCCESS)
            g_GotExt = true;
        g_TriedNoMsgExt = true;
        if (g_TriedExt)
            g_TriedExt = true;
    }

    return g_GotExt;
}

s3eBool s3ePushWooshAvailable()
{
    _extLoadNoMsg();
    return g_GotExt ? S3E_TRUE : S3E_FALSE;
}

s3eResult s3ePushWooshRegister(s3ePushWooshCallback cbid, s3eCallback fn, void* userData)
{
    IwTrace(PUSHWOOSH_VERBOSE, ("calling s3ePushWoosh[0] func: s3ePushWooshRegister"));

    if (!_extLoad())
        return S3E_RESULT_ERROR;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    s3eResult ret = g_Ext.m_s3ePushWooshRegister(cbid, fn, userData);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

s3eResult s3ePushWooshUnRegister(s3ePushWooshCallback cbid, s3eCallback fn)
{
    IwTrace(PUSHWOOSH_VERBOSE, ("calling s3ePushWoosh[1] func: s3ePushWooshUnRegister"));

    if (!_extLoad())
        return S3E_RESULT_ERROR;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    s3eResult ret = g_Ext.m_s3ePushWooshUnRegister(cbid, fn);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

s3eBool s3ePushWooshNotificationsAvailable()
{
    IwTrace(PUSHWOOSH_VERBOSE, ("calling s3ePushWoosh[2] func: s3ePushWooshNotificationsAvailable"));

    if (!_extLoad())
        return S3E_FALSE;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    s3eBool ret = g_Ext.m_s3ePushWooshNotificationsAvailable();

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

s3eResult s3ePushWooshNotificationRegister()
{
    IwTrace(PUSHWOOSH_VERBOSE, ("calling s3ePushWoosh[3] func: s3ePushWooshNotificationRegister"));

    if (!_extLoad())
        return S3E_RESULT_SUCCESS;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    s3eResult ret = g_Ext.m_s3ePushWooshNotificationRegister();

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

char * s3ePushWooshGetToken()
{
    IwTrace(PUSHWOOSH_VERBOSE, ("calling s3ePushWoosh[4] func: s3ePushWooshGetToken"));

    if (!_extLoad())
        return 0;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    char * ret = g_Ext.m_s3ePushWooshGetToken();

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

s3eResult s3ePushWooshNotificationUnRegister()
{
    IwTrace(PUSHWOOSH_VERBOSE, ("calling s3ePushWoosh[5] func: s3ePushWooshNotificationUnRegister"));

    if (!_extLoad())
        return S3E_RESULT_SUCCESS;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    s3eResult ret = g_Ext.m_s3ePushWooshNotificationUnRegister();

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

s3eResult s3ePushWooshNotificationSetIntTag(const char * tagName, int tagValue)
{
    IwTrace(PUSHWOOSH_VERBOSE, ("calling s3ePushWoosh[6] func: s3ePushWooshNotificationSetIntTag"));

    if (!_extLoad())
        return S3E_RESULT_SUCCESS;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    s3eResult ret = g_Ext.m_s3ePushWooshNotificationSetIntTag(tagName, tagValue);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

s3eResult s3ePushWooshNotificationSetStringTag(const char * tagName, const char * tagValue)
{
    IwTrace(PUSHWOOSH_VERBOSE, ("calling s3ePushWoosh[7] func: s3ePushWooshNotificationSetStringTag"));

    if (!_extLoad())
        return S3E_RESULT_SUCCESS;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    s3eResult ret = g_Ext.m_s3ePushWooshNotificationSetStringTag(tagName, tagValue);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

s3eResult s3ePushWooshNotificationSetBadgeNumber(int badgeValue)
{
    IwTrace(PUSHWOOSH_VERBOSE, ("calling s3ePushWoosh[8] func: s3ePushWooshNotificationSetBadgeNumber"));

    if (!_extLoad())
        return S3E_RESULT_SUCCESS;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    s3eResult ret = g_Ext.m_s3ePushWooshNotificationSetBadgeNumber(badgeValue);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

s3eResult s3ePushWooshClearLocalNotifications()
{
    IwTrace(PUSHWOOSH_VERBOSE, ("calling s3ePushWoosh[9] func: s3ePushWooshClearLocalNotifications"));

    if (!_extLoad())
        return S3E_RESULT_SUCCESS;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    s3eResult ret = g_Ext.m_s3ePushWooshClearLocalNotifications();

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

s3eResult s3ePushWooshStartLocationTracking()
{
    IwTrace(PUSHWOOSH_VERBOSE, ("calling s3ePushWoosh[10] func: s3ePushWooshStartLocationTracking"));

    if (!_extLoad())
        return S3E_RESULT_SUCCESS;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    s3eResult ret = g_Ext.m_s3ePushWooshStartLocationTracking();

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

s3eResult s3ePushWooshStopLocationTracking()
{
    IwTrace(PUSHWOOSH_VERBOSE, ("calling s3ePushWoosh[11] func: s3ePushWooshStopLocationTracking"));

    if (!_extLoad())
        return S3E_RESULT_SUCCESS;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    s3eResult ret = g_Ext.m_s3ePushWooshStopLocationTracking();

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

s3eResult s3ePushWooshScheduleLocalNotification(const char * message, int seconds, const char * userdata)
{
    IwTrace(PUSHWOOSH_VERBOSE, ("calling s3ePushWoosh[12] func: s3ePushWooshScheduleLocalNotification"));

    if (!_extLoad())
        return S3E_RESULT_SUCCESS;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    s3eResult ret = g_Ext.m_s3ePushWooshScheduleLocalNotification(message, seconds, userdata);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

s3eResult s3ePushWooshSetAndroidNotificationMultiMode(bool enable)
{
    IwTrace(PUSHWOOSH_VERBOSE, ("calling s3ePushWoosh[13] func: s3ePushWooshSetAndroidNotificationMultiMode"));

    if (!_extLoad())
        return S3E_RESULT_SUCCESS;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    s3eResult ret = g_Ext.m_s3ePushWooshSetAndroidNotificationMultiMode(enable);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}
