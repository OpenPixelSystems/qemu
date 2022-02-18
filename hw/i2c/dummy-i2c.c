#include "qemu/osdep.h"
#include "qapi/error.h"
#include "hw/i2c/i2c.h"
#include "hw/i2c/smbus_slave.h"
#include "hw/qdev-core.h"
#include "hw/sysbus.h"
#include "qemu/log.h"
#include "qemu/module.h"
#include "qemu/queue.h"
#include "qom/object.h"
#include "trace.h"

#define TYPE_DUMMY_I2C "dummy_i2c"

typedef struct {
    I2CSlave i2c;
    uint8_t control;
}DummyI2CState;

static void dummy_i2c_get_data(Object *obj, Visitor *v, const char *name,
        void *opaque, Error **errp)
{

}

static void dummy_i2c_set_data(Object *obj, Visitor *v, const char *name,
        void *opaque, Error **errp)
{

}

static uint8_t dummy_i2c_recv(I2CSlave *i2c)
{

    return 0;
}

static int dummy_i2c_send(I2CSlave *i2c, uint8_t data)
{

    return 0;
}

static int dummy_i2c_event(I2CSlave *i2c, enum i2c_event event)
{
    return 0;
}

static void dummy_i2c_realize(DeviceState *dev, Error **errp)
{
    printf("Running i2c realize\n");
}

static void dummy_i2c_init(Object *obj)
{
    object_property_add(obj, "dummy_data", "int",
            dummy_i2c_get_data, dummy_i2c_set_data,
            NULL, NULL);
}

static void dummy_i2c_class_init(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);
    I2CSlaveClass *sc = I2C_SLAVE_CLASS(klass);

    dc->realize = dummy_i2c_realize;
    sc->event = dummy_i2c_event;
    sc->recv = dummy_i2c_recv;
    sc->send = dummy_i2c_send;
}

static const TypeInfo dummy_i2c_info = {
    .name = TYPE_DUMMY_I2C,
    .parent = TYPE_I2C_SLAVE,
    .instance_size = sizeof(DummyI2CState),
    .instance_init = dummy_i2c_init,
    .class_init = dummy_i2c_class_init,
    .abstract = true,
};

static void dummy_i2c_register_types(void)
{
    type_register_static(&dummy_i2c_info);
}

type_init(dummy_i2c_register_types);
