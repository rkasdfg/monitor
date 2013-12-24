#ifdef MONITOR_EXPORTS
#define MONITOR_API __declspec(dllexport)
#else
#define MONITOR_API __declspec(dllimport)
#endif
