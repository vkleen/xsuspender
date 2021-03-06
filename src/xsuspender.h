#ifndef XSUSPENDER_XSUSPENDER_H
#define XSUSPENDER_XSUSPENDER_H

#include <glib.h>
#include <libwnck/libwnck.h>

#include "entry.h"
#include "rule.h"


#ifndef PROJECT_NAME
#warning "PROJECT_NAME undefined"
#define PROJECT_NAME "xsuspender"
#endif

#ifndef PROJECT_VERSION
#warning "PROJECT_VERSION undefined"
#define PROJECT_VERSION "0"
#endif

#ifndef EXAMPLE_CONF
#warning "EXAMPLE_CONF undefined"
#define EXAMPLE_CONF "/usr/share/doc/xsuspender/examples/xsuspender.conf"
#endif


gboolean IS_DEBUG;
gboolean is_battery_powered;

GSList *suspended_entries;   // List of suspended WindowEntry
GSList *queued_entries;

Rule **rules;  // Matching rules from config files


gboolean xsus_signal_stop (WindowEntry *entry);
gboolean xsus_signal_continue (WindowEntry *entry);
void     xsus_window_entry_enqueue (WindowEntry *entry, unsigned delay);
void     xsus_window_suspend (WnckWindow *window);
void     xsus_window_resume (WnckWindow *window);
int      xsus_init ();
void     xsus_exit ();

#endif  // XSUSPENDER_XSUSPENDER_H
