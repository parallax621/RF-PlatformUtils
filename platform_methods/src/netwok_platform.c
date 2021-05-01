#include "netwok_platform.h"
#include "memory_platform.h"

network_platform_t network_platform;
void init_network_platform(network_platform_dependent_methods_t *methods)
{
    network_platform.network_methods = *methods;
}

void set_adapter_settings(rfUint32 host_mask, rfUint32 host_ip_addr)
{
    network_platform.network_settings.host_mask = host_mask;
    network_platform.network_settings.host_ip_addr = host_ip_addr;
}
