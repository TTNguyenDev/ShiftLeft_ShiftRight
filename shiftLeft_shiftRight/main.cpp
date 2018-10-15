#include <iostream>

using namespace std;

unsigned int mergeIPAddress(unsigned char ipNeedToMerge[4]) {
    unsigned int newip;
    newip = ipNeedToMerge[0];
    
    for (int i = 1; i < 4; i++) {
        newip = newip << 8;
        newip = newip | ipNeedToMerge[i];
    }
    return newip;
}

void rawIP(unsigned int ip, unsigned char ipAddress[4]) {
    for (int i = 3; i >= 0; i--) {
        ipAddress[i] = ip;
        ip = ip >> 8;
    }
}

int main() {
    unsigned char ip[4] = {192, 168, 32, 111};
    unsigned char ips[4];
    
    uint32_t mergedIP = mergeIPAddress(ip);
    rawIP(mergedIP, ips);
    
    for (int i = 0; i < 4; i++) {
        printf("%u\n", ips[i]);
    }
    return 0;
}
