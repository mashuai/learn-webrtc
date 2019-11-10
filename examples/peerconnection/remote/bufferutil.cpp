#include "bufferutil.h"

void BufferUtil::write32(QBuffer &buffer, quint32 value)
{
    buffer.putChar(value >> 24);
    buffer.putChar(value >> 16);
    buffer.putChar(value >> 8);
    buffer.putChar(value);
}

void BufferUtil::write16(QBuffer &buffer, quint32 value)
{
    buffer.putChar(value >> 8);
    buffer.putChar(value);
}

void BufferUtil::writeFloat(QBuffer &buffer, float value)
{
    buffer.write((char*)&value, 4);
}

quint16 BufferUtil::read16(QBuffer &buffer)
{
    uchar c;
    quint16 ret = 0;
    buffer.getChar(reinterpret_cast<char*>(&c));
    ret |= (c << 8);
    buffer.getChar(reinterpret_cast<char*>(&c));
    ret |= c;

    return ret;
}

quint32 BufferUtil::read32(QBuffer &buffer)
{
    uchar c;
    quint32 ret = 0;
    buffer.getChar(reinterpret_cast<char*>(&c));
    ret |= (c << 24);
    buffer.getChar(reinterpret_cast<char*>(&c));
    ret |= (c << 16);
    buffer.getChar(reinterpret_cast<char*>(&c));
    ret |= (c << 8);
    buffer.getChar(reinterpret_cast<char*>(&c));
    ret |= c;

    return ret;
}

quint64 BufferUtil::read64(QBuffer &buffer)
{
    quint32 msb = read32(buffer);
    quint32 lsb = read32(buffer);

    return ((quint64) msb << 32) | lsb;;
}

float BufferUtil::readFloat(QBuffer &buffer)
{
    float ret = 0;
    buffer.read((char*)&ret, 4);
    return ret;
}
