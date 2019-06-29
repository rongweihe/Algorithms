
public static boolean isInnerIP(String ipAddress)
{
    boolean isInnerIp = false;
    long ipNum = getIpNum(ipAddress);
    /**
    私有IP：A类  10.0.0.0-10.255.255.255
           B类  172.16.0.0-172.31.255.255
           C类  192.168.0.0-192.168.255.255
    当然，还有127这个网段是环回地址
    **/
    long aBegin = getIpNum("10.0.0.0");
    long aEnd = getIpNum("10.255.255.255");
    long bBegin = getIpNum("172.16.0.0");
    long bEnd = getIpNum("172.31.255.255");
    long cBegin = getIpNum("192.168.0.0");
    long cEnd = getIpNum("192.168.255.255");
    isInnerIp = isInner(ipNum,aBegin,aEnd) || isInner(ipNum,bBegin,bEnd) || isInner(ipNum,cBegin,cEnd) || ipAddress.equals("127.0.0.1");
    return isInnerIp;
}
private static long getIpNum(String ipAddress)
{
    String [] ip = ipAddress.split("\\.");
    long a = Integer.parseInt(ip[0]);
    long b = Integer.parseInt(ip[1]);
    long c = Integer.parseInt(ip[2]);
    long d = Integer.parseInt(ip[3]);

    long ipNum = a * Math.pow(256,3) + b * Math.pow(256,2) + c * 256 + d;
    return ipNum;
}
private static boolean isInner(long userIp,long begin,long end)
{
    return (userIp>=begin) && (userIp<=end);
}
