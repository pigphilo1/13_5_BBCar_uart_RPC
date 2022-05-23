/*
 * Generated by erpcgen 1.9.0 on Thu May 19 16:27:31 2022.
 *
 * AUTOGENERATED - DO NOT EDIT
 */


#include "bbcar_control_server.h"
#if ERPC_ALLOCATION_POLICY == ERPC_ALLOCATION_POLICY_DYNAMIC
#include <new>
#include "erpc_port.h"
#endif
#include "erpc_manually_constructed.h"

#if 10900 != ERPC_VERSION_NUMBER
#error "The generated shim code version is different to the rest of eRPC code."
#endif

using namespace erpc;
using namespace std;

#if ERPC_NESTED_CALLS_DETECTION
extern bool nestingDetection;
#endif

ERPC_MANUALLY_CONSTRUCTED_STATIC(BBCarService_service, s_BBCarService_service);



// Call the correct server shim based on method unique ID.
erpc_status_t BBCarService_service::handleInvocation(uint32_t methodId, uint32_t sequence, Codec * codec, MessageBufferFactory *messageFactory)
{
    erpc_status_t erpcStatus;
    switch (methodId)
    {
        case kBBCarService_stop_id:
        {
            erpcStatus = stop_shim(codec, messageFactory, sequence);
            break;
        }

        case kBBCarService_goStraight_id:
        {
            erpcStatus = goStraight_shim(codec, messageFactory, sequence);
            break;
        }

        case kBBCarService_turn_id:
        {
            erpcStatus = turn_shim(codec, messageFactory, sequence);
            break;
        }

        default:
        {
            erpcStatus = kErpcStatus_InvalidArgument;
            break;
        }
    }

    return erpcStatus;
}

// Server shim for stop of BBCarService interface.
erpc_status_t BBCarService_service::stop_shim(Codec * codec, MessageBufferFactory *messageFactory, uint32_t sequence)
{
    erpc_status_t err = kErpcStatus_Success;

    uint8_t car;

    // startReadMessage() was already called before this shim was invoked.

    codec->read(&car);

    err = codec->getStatus();
    if (err == kErpcStatus_Success)
    {
        // Invoke the actual served function.
#if ERPC_NESTED_CALLS_DETECTION
        nestingDetection = true;
#endif
        stop(car);
#if ERPC_NESTED_CALLS_DETECTION
        nestingDetection = false;
#endif

        // preparing MessageBuffer for serializing data
        err = messageFactory->prepareServerBufferForSend(codec->getBuffer());
    }

    if (err == kErpcStatus_Success)
    {
        // preparing codec for serializing data
        codec->reset();

        // Build response message.
        codec->startWriteMessage(kReplyMessage, kBBCarService_service_id, kBBCarService_stop_id, sequence);

        err = codec->getStatus();
    }

    return err;
}

// Server shim for goStraight of BBCarService interface.
erpc_status_t BBCarService_service::goStraight_shim(Codec * codec, MessageBufferFactory *messageFactory, uint32_t sequence)
{
    erpc_status_t err = kErpcStatus_Success;

    uint8_t car;
    int32_t speed;

    // startReadMessage() was already called before this shim was invoked.

    codec->read(&car);

    codec->read(&speed);

    err = codec->getStatus();
    if (err == kErpcStatus_Success)
    {
        // Invoke the actual served function.
#if ERPC_NESTED_CALLS_DETECTION
        nestingDetection = true;
#endif
        goStraight(car, speed);
#if ERPC_NESTED_CALLS_DETECTION
        nestingDetection = false;
#endif

        // preparing MessageBuffer for serializing data
        err = messageFactory->prepareServerBufferForSend(codec->getBuffer());
    }

    if (err == kErpcStatus_Success)
    {
        // preparing codec for serializing data
        codec->reset();

        // Build response message.
        codec->startWriteMessage(kReplyMessage, kBBCarService_service_id, kBBCarService_goStraight_id, sequence);

        err = codec->getStatus();
    }

    return err;
}

// Server shim for turn of BBCarService interface.
erpc_status_t BBCarService_service::turn_shim(Codec * codec, MessageBufferFactory *messageFactory, uint32_t sequence)
{
    erpc_status_t err = kErpcStatus_Success;

    uint8_t car;
    int32_t speed;
    double factor;

    // startReadMessage() was already called before this shim was invoked.

    codec->read(&car);

    codec->read(&speed);

    codec->read(&factor);

    err = codec->getStatus();
    if (err == kErpcStatus_Success)
    {
        // Invoke the actual served function.
#if ERPC_NESTED_CALLS_DETECTION
        nestingDetection = true;
#endif
        turn(car, speed, factor);
#if ERPC_NESTED_CALLS_DETECTION
        nestingDetection = false;
#endif

        // preparing MessageBuffer for serializing data
        err = messageFactory->prepareServerBufferForSend(codec->getBuffer());
    }

    if (err == kErpcStatus_Success)
    {
        // preparing codec for serializing data
        codec->reset();

        // Build response message.
        codec->startWriteMessage(kReplyMessage, kBBCarService_service_id, kBBCarService_turn_id, sequence);

        err = codec->getStatus();
    }

    return err;
}

#if ERPC_ALLOCATION_POLICY == ERPC_ALLOCATION_POLICY_DYNAMIC
erpc_service_t create_BBCarService_service()
{
    return new (nothrow) BBCarService_service();
}

void destroy_BBCarService_service(erpc_service_t *service)
{
    if (*service)
    {
        delete service;
    }
}
#elif ERPC_ALLOCATION_POLICY == ERPC_ALLOCATION_POLICY_STATIC
erpc_service_t create_BBCarService_service()
{
    s_BBCarService_service.construct();
    return s_BBCarService_service.get();
}

void destroy_BBCarService_service()
{
    s_BBCarService_service.destroy();
}
#else
#warning "Unknown eRPC allocation policy!"
#endif
