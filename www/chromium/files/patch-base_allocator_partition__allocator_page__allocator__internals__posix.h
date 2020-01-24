--- base/allocator/partition_allocator/page_allocator_internals_posix.h.orig	2019-10-21 19:06:18 UTC
+++ base/allocator/partition_allocator/page_allocator_internals_posix.h
@@ -19,7 +19,7 @@
 #if defined(OS_ANDROID)
 #include <sys/prctl.h>
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_BSD) || defined(OS_LINUX)
 #include <sys/resource.h>
 
 #include <algorithm>
