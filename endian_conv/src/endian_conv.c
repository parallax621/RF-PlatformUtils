#include "endian_conv.h"
#include "memory_platform.h"
#include "netwok_platform.h"


rf_endianess g_platform_endianess = kEndianessUnknown;

/* THESE ROUTINES MODIFY THE BUFFER POINTER*/


rfInt8 get_rfInt8_from_packet(rfUint8 **buffer_address)
{
    rfUint8 *buffer = (rfUint8*)*buffer_address;
    rfInt8 data = (rfInt8)buffer[0];
    *buffer_address += sizeof (rfInt8);
    return data;
}


rfUint8 get_rfUint8_from_packet(rfUint8 **buffer_address)
{
    rfUint8 *buffer = (rfUint8*)*buffer_address;
    rfUint8 data = (rfUint8)buffer[0];
    *buffer_address += sizeof (rfUint8);
    return data;
}

rfChar  get_rfChar_from_packet (rfUint8** buffer_address)
{
    rfUint8 *buffer = (rfUint8*)*buffer_address;
    rfChar data = (rfChar)buffer[0];
    *buffer_address += sizeof (rfChar);
    return data;
}

rfByte  get_rfByte_from_packet (rfUint8** buffer_address)
{
    rfUint8 *buffer = (rfUint8*)*buffer_address;
    rfByte data = (rfByte)buffer[0];
    *buffer_address += sizeof (rfByte);
    return data;
}

rfBool  get_rfBool_from_packet (rfUint8** buffer_address)
{
    rfUint8 *buffer = (rfUint8*)*buffer_address;
    rfBool data = (rfBool)buffer[0];
    *buffer_address += sizeof (rfBool);
    return data;
}



rfInt16  get_rfInt16_from_packet (rfUint8** buffer_address, rf_endianess endian)
{
    rfUint8 *buffer = (rfUint8*)*buffer_address;
    rfInt16 data = 0;
    if(endian == kEndianessLittle)
        data = ((rfInt16)buffer[0]) | (((rfInt16)buffer[1]) << 8);
    else
        data = ((rfInt16)buffer[1]) | (((rfInt16)buffer[0]) << 8);
    *buffer_address += sizeof (rfInt16);
    return data;
}


rfUint16 get_rfUint16_from_packet(rfUint8** buffer_address, rf_endianess endian)
{
    rfUint8 *buffer = (rfUint8*)*buffer_address;
    rfUint16 data = 0;
    if(endian == kEndianessLittle)
        data = ((rfUint16)buffer[0]) | (((rfUint16)buffer[1]) << 8);
    else
        data = ((rfUint16)buffer[1]) | (((rfUint16)buffer[0]) << 8);
    *buffer_address += sizeof (rfUint16);
    return data;
}



rfInt32  get_rfInt32_from_packet (rfUint8** buffer_address, rf_endianess endian)
{
    rfUint8 *buffer = (rfUint8*)*buffer_address;
    rfInt32 data = 0;
    if(endian == kEndianessLittle)
        data =  ((rfInt32) buffer[0]) |
                (((rfInt32)buffer[1]) << 8) |
                (((rfInt32)buffer[2]) << 16) |
                (((rfInt32)buffer[3]) << 24);
    else
        data =  ((rfInt32) buffer[3]) |
                (((rfInt32)buffer[2]) << 8) |
                (((rfInt32)buffer[1]) << 16) |
                (((rfInt32)buffer[0]) << 24);
    *buffer_address += sizeof (rfInt32);
    return data;
}

rfUint32 get_rfUint32_from_packet(rfUint8** buffer_address, rf_endianess endian)
{
    rfUint8 *buffer = (rfUint8*)*buffer_address;
    rfUint32 data = 0;
    if(endian == kEndianessLittle)
        data =  ((rfUint32) buffer[0]) |
                (((rfUint32)buffer[1]) << 8) |
                (((rfUint32)buffer[2]) << 16) |
                (((rfUint32)buffer[3]) << 24);
    else
        data =  ((rfUint32) buffer[3]) |
                (((rfUint32)buffer[2]) << 8) |
                (((rfUint32)buffer[1]) << 16) |
                (((rfUint32)buffer[0]) << 24);
    *buffer_address += sizeof (rfUint32);
    return data;
}

rfSize get_array_from_packet(
        rfUint8* destination_buffer, rfUint8** source_buffer_address, rfSize num)
{
    rfUint8 *p = (rfUint8*)*source_buffer_address;
    memory_platform.rf_memcpy(destination_buffer, p, num);
    return move_packet_n_bytes(num, source_buffer_address);
}



rfSize add_rfInt8_to_packet (rfInt8 data, rfUint8** buffer_address)
{
     rfUint8 *p = (rfUint8*)*buffer_address;
     p[0] = data;
     *buffer_address += 1;
     return 1;
}

rfSize add_rfUint8_to_packet(rfUint8 data, rfUint8** buffer_address)
{
    rfUint8 *p = (rfUint8*)*buffer_address;
    p[0] = data;
    *buffer_address += 1;
    return 1;
}

rfSize add_rfChar_to_packet (rfChar data, rfUint8** buffer_address)
{
    rfUint8 *p = (rfUint8*)*buffer_address;
    p[0] = data;
    *buffer_address += 1;
    return 1;
}

rfSize add_rfByte_to_packet (rfByte data, rfUint8** buffer_address)
{
    rfUint8 *p = (rfUint8*)*buffer_address;
    p[0] = data;
    *buffer_address += 1;
    return 1;
}

rfSize add_rfBool_to_packet (rfBool data, rfUint8** buffer_address)
{
    rfUint8 *p = (rfUint8*)*buffer_address;
    p[0] = data;
    *buffer_address += 1;
    return 1;
}

rfSize add_rfInt16_to_packet (rfInt16 data, rfUint8** buffer_address, rf_endianess endian)
{
    rfUint8 *p = (rfUint8*)*buffer_address;
    if(endian == kEndianessLittle)
    {
        p[0] = (data) & 0xFF;
        p[1] = (data >> 8) & 0xFF;
    }
    else
    {
        p[1] = (data) & 0xFF;
        p[0] = (data >> 8) & 0xFF;
    }

    (*buffer_address) += sizeof (rfInt16);

    return sizeof (rfInt16);
}

rfSize add_rfUint16_to_packet(rfUint16 data, rfUint8** buffer_address, rf_endianess endian)
{
    rfUint8 *p = (rfUint8*)*buffer_address;
    if(endian == kEndianessLittle)
    {
        p[0] = (data) & 0xFF;
        p[1] = (data >> 8) & 0xFF;
    }
    else
    {
        p[1] = (data) & 0xFF;
        p[0] = (data >> 8) & 0xFF;
    }

    (*buffer_address) += sizeof (rfUint16);

    return sizeof (rfUint16);
}

rfSize add_rfInt32_to_packet (rfInt32 data, rfUint8** buffer_address, rf_endianess endian)
{
    rfUint8 *p = (rfUint8*)*buffer_address;
    if(endian == kEndianessLittle)
    {
        p[0] = (data) & 0xFF;
        p[1] = (data >> 8) & 0xFF;
        p[2] = (data >> 16) & 0xFF;
        p[3] = (data >> 24) & 0xFF;
    }
    else
    {
        p[3] = (data) & 0xFF;
        p[2] = (data >> 8) & 0xFF;
        p[1] = (data >> 16) & 0xFF;
        p[0] = (data >> 24) & 0xFF;
    }

    (*buffer_address) += sizeof (rfInt32);

    return sizeof (rfInt32);
}

rfSize add_rfUint32_to_packet(rfUint32 data, rfUint8** buffer_address, rf_endianess endian)
{
    rfUint8 *p = (rfUint8*)*buffer_address;
    if(endian == kEndianessLittle)
    {
        p[0] = (data) & 0xFF;
        p[1] = (data >> 8) & 0xFF;
        p[2] = (data >> 16) & 0xFF;
        p[3] = (data >> 24) & 0xFF;
    }
    else
    {
        p[3] = (data) & 0xFF;
        p[2] = (data >> 8) & 0xFF;
        p[1] = (data >> 16) & 0xFF;
        p[0] = (data >> 24) & 0xFF;
    }

    (*buffer_address) += sizeof (rfUint32);

    return sizeof (rfUint32);
}

#ifdef _SUPPORT_64BIT_DATATYPES

rfUint64 get_rfUint64_from_packet(rfUint8** buffer_address, rf_endianess endian)
{
    rfUint8 *buffer = (rfUint8*)*buffer_address;
    rfUint64 data = 0;
    if(endian == kEndianessLittle)
        data =  ((rfUint64) buffer[0]) |
                (((rfUint64)buffer[1]) << 8) |
                (((rfUint64)buffer[2]) << 16) |
                (((rfUint64)buffer[3]) << 24) |
                (((rfUint64)buffer[4]) << 32) |
                (((rfUint64)buffer[5]) << 40) |
                (((rfUint64)buffer[6]) << 48) |
                (((rfUint64)buffer[7]) << 56);
    else
        data =  ((rfUint64) buffer[7]) |
                (((rfUint64)buffer[6]) << 8) |
                (((rfUint64)buffer[5]) << 16) |
                (((rfUint64)buffer[4]) << 24) |
                (((rfUint64)buffer[3]) << 32) |
                (((rfUint64)buffer[2]) << 40) |
                (((rfUint64)buffer[1]) << 48) |
                (((rfUint64)buffer[0]) << 56);
    *buffer_address += sizeof (rfUint64);
    return data;
}

rfUint64 get_rfInt64_from_packet(rfUint8** buffer_address, rf_endianess endian)
{
    rfUint8 *buffer = (rfUint8*)*buffer_address;
    rfUint64 data = 0;
    if(endian == kEndianessLittle)
        data =  ((rfInt64) buffer[0]) |
                (((rfInt64)buffer[1]) << 8) |
                (((rfInt64)buffer[2]) << 16) |
                (((rfInt64)buffer[3]) << 24) |
                (((rfInt64)buffer[4]) << 32) |
                (((rfInt64)buffer[5]) << 40) |
                (((rfInt64)buffer[6]) << 48) |
                (((rfInt64)buffer[7]) << 56);
    else
        data =  ((rfInt64) buffer[7]) |
                (((rfInt64)buffer[6]) << 8) |
                (((rfInt64)buffer[5]) << 16) |
                (((rfInt64)buffer[4]) << 24) |
                (((rfInt64)buffer[3]) << 32) |
                (((rfInt64)buffer[2]) << 40) |
                (((rfInt64)buffer[1]) << 48) |
                (((rfInt64)buffer[0]) << 56);
    *buffer_address += sizeof (rfInt64);
    return data;
}

rfSize add_rfUint64_to_packet(rfUint64 data, rfUint8** buffer_address, rf_endianess endian)
{
    rfUint8 *p = (rfUint8*)*buffer_address;
    if(endian == kEndianessLittle)
    {
        p[0] = (data) & 0xFF;
        p[1] = (data >> 8) & 0xFF;
        p[2] = (data >> 16) & 0xFF;
        p[3] = (data >> 24) & 0xFF;
        p[4] = (data >> 32) & 0xFF;
        p[5] = (data >> 40) & 0xFF;
        p[6] = (data >> 48) & 0xFF;
        p[7] = (data >> 56) & 0xFF;
    }
    else
    {
        p[7] = (data) & 0xFF;
        p[6] = (data >> 8) & 0xFF;
        p[5] = (data >> 16) & 0xFF;
        p[4] = (data >> 24) & 0xFF;
        p[3] = (data >> 24) & 0xFF;
        p[2] = (data >> 24) & 0xFF;
        p[1] = (data >> 24) & 0xFF;
        p[0] = (data >> 24) & 0xFF;
    }

    (*buffer_address) += sizeof (rfUint64);

    return sizeof (rfUint64);
}

rfSize add_rfInt64_to_packet(rfInt64 data, rfUint8** buffer_address, rf_endianess endian)
{
    rfUint8 *p = (rfUint8*)*buffer_address;
    if(endian == kEndianessLittle)
    {
        p[0] = (data) & 0xFF;
        p[1] = (data >> 8) & 0xFF;
        p[2] = (data >> 16) & 0xFF;
        p[3] = (data >> 24) & 0xFF;
        p[4] = (data >> 32) & 0xFF;
        p[5] = (data >> 40) & 0xFF;
        p[6] = (data >> 48) & 0xFF;
        p[7] = (data >> 56) & 0xFF;
    }
    else
    {
        p[7] = (data) & 0xFF;
        p[6] = (data >> 8) & 0xFF;
        p[5] = (data >> 16) & 0xFF;
        p[4] = (data >> 24) & 0xFF;
        p[3] = (data >> 24) & 0xFF;
        p[2] = (data >> 24) & 0xFF;
        p[1] = (data >> 24) & 0xFF;
        p[0] = (data >> 24) & 0xFF;
    }

    (*buffer_address) += sizeof (rfInt64);

    return sizeof (rfInt64);
}

#endif


void determine_endianess() {
    rfInt i = 1;
    rfChar *p = (char *)&i;
    if (p[0] == 1)
    {
        g_platform_endianess = kEndianessLittle;
    }
    else
    {
        g_platform_endianess = kEndianessBig;
    }
}

rfInt8 get_endianess(void) {
    return g_platform_endianess;
}

rfSize move_packet_n_bytes(
        rfInt n, rfUint8** packet_runner)
{
    (*packet_runner) += n;
    return n;
}

rfSize fill_next_n_packet_bytes_with(
        rfUint8 value, rfUint32 n, rfUint8** packet)
{
    memory_platform.rf_memset(*packet, value, n);
    return n;
}

rfSize fill_next_n_packet_bytes_with_value_and_move_to_next_position(
        rfUint8 value, rfUint32 n, rfUint8** packet)
{
    fill_next_n_packet_bytes_with(value, n, packet);
    move_packet_n_bytes(n, (rfUint8**)packet);
    return n;
}

