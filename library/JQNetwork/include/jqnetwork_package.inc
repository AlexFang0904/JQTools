﻿/*
    This file is part of JQNetwork
    
    Library introduce: https://github.com/188080501/JQNetwork

    Copyright: Jason

    Contact email: Jason@JasonServer.com
    
    GitHub: https://github.com/188080501/
*/

#ifndef JQNETWORK_INCLUDE_JQNETWORK_PACKAGE_INC_
#define JQNETWORK_INCLUDE_JQNETWORK_PACKAGE_INC_

// JQNetwork lib import
#include "jqnetwork_package.h"

inline int JQNetworkPackage::headSize()
{
    return sizeof( head_ );
}

inline bool JQNetworkPackage::isCompletePackage() const 
{ 
    return isCompletePackage_; 
}

inline bool JQNetworkPackage::isAbandonPackage() const 
{ 
    return isAbandonPackage_;
}

inline qint8 JQNetworkPackage::bootFlag() const 
{ 
    return head_.bootFlag_; 
}

inline qint8 JQNetworkPackage::packageFlag() const 
{ 
    return head_.packageFlag_; 
}

inline qint32 JQNetworkPackage::randomFlag() const 
{ 
    return head_.randomFlag_; 
}

inline qint8 JQNetworkPackage::metaDataFlag() const 
{ 
    return head_.metaDataFlag_;
}

inline qint32 JQNetworkPackage::metaDataTotalSize() const 
{ 
    return head_.metaDataTotalSize_; 
}

inline qint32 JQNetworkPackage::metaDataCurrentSize() const 
{ 
    return head_.metaDataCurrentSize_; 
}

inline qint8 JQNetworkPackage::payloadDataFlag() const 
{ 
    return head_.payloadDataFlag_; 
}

inline qint32 JQNetworkPackage::payloadDataTotalSize() const 
{ 
    return head_.payloadDataTotalSize_; 
}

inline qint32 JQNetworkPackage::payloadDataCurrentSize() const 
{ 
    return head_.payloadDataCurrentSize_; 
}

inline QByteArray JQNetworkPackage::metaData() const 
{ 
    return metaData_; 
}

inline int JQNetworkPackage::metaDataSize() const
{
    return metaData_.size();
}

inline QByteArray JQNetworkPackage::payloadData() const 
{ 
    return payloadData_; 
}

inline int JQNetworkPackage::payloadDataSize() const
{
    return payloadData_.size();
}

inline qint32 JQNetworkPackage::metaDataOriginalIndex() const
{
    return metaDataOriginalIndex_;
}

inline qint32 JQNetworkPackage::metaDataOriginalCurrentSize() const
{
    return metaDataOriginalCurrentSize_;
}

inline qint32 JQNetworkPackage::payloadDataOriginalIndex() const
{
    return payloadDataOriginalIndex_;
}

inline qint32 JQNetworkPackage::payloadDataOriginalCurrentSize() const
{
    return payloadDataOriginalCurrentSize_;
}

inline QVariantMap JQNetworkPackage::metaDataInVariantMap() const
{
    return metaDataInVariantMap_;
}

inline QString JQNetworkPackage::targetActionFlag() const
{
    return ( metaDataInVariantMap_.contains( "targetActionFlag" ) ) ? ( metaDataInVariantMap_[ "targetActionFlag" ].toString() ) : ( QString() );
}

inline QVariantMap JQNetworkPackage::appendData() const
{
    return ( metaDataInVariantMap_.contains( "appendData" ) ) ? ( metaDataInVariantMap_[ "appendData" ].toMap() ) : ( QVariantMap() );
}

inline QString JQNetworkPackage::fileName() const
{
    return ( metaDataInVariantMap_.contains( "fileName" ) ) ? ( metaDataInVariantMap_[ "fileName" ].toString() ) : ( QString() );
}

inline qint64 JQNetworkPackage::fileSize() const
{
    return ( metaDataInVariantMap_.contains( "fileSize" ) ) ? ( metaDataInVariantMap_[ "fileSize" ].toLongLong() ) : ( -1 );
}

inline qint32 JQNetworkPackage::filePermissions() const
{
    return ( metaDataInVariantMap_.contains( "filePermissions" ) ) ? ( metaDataInVariantMap_[ "filePermissions" ].toInt() ) : ( 0 );
}

inline bool JQNetworkPackage::containsFile() const
{
    return !localFilePath_.isEmpty();
}

inline QString JQNetworkPackage::localFilePath() const
{
    return localFilePath_;
}

inline void JQNetworkPackage::setLocalFilePath(const QString &localFilePath)
{
    localFilePath_ = localFilePath;
}

inline void JQNetworkPackage::clearMetaData()
{
    metaData_.clear();
}

inline void JQNetworkPackage::clearPayloadData()
{
    payloadData_.clear();
}

inline QByteArray JQNetworkPackage::toByteArray() const
{
    QByteArray buffer;

    buffer.append( reinterpret_cast< const char * >( &head_ ), JQNetworkPackage::headSize() );
    if ( head_.metaDataCurrentSize_ > 0 )
    {
        buffer.append( metaData_ );
    }
    if ( head_.payloadDataCurrentSize_ > 0 )
    {
        buffer.append( payloadData_ );
    }

    return buffer;
}

#endif//JQNETWORK_INCLUDE_JQNETWORK_PACKAGE_INC_
