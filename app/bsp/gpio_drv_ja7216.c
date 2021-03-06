//
// gpio0.0 for sda
// gpio0.1 for scl
// gpio0.2 for sio0 asynp
// gpio0.3 for sio0 aclkp
// gpio0.4 for keypad column4
// gpio0.5 for device reset
// gpio0.6 for motion detection interrupt
// gpio0.7 for buzzer
//
// gpio1.0 for ir receiver
// gpio1.1 for eth col
// gpio1.2 for eth crs
// gpio1.3 for rec led
// gpio1.4 for running led
// gpio1.5 for sensor 2 in
// gpio1.6 for sensor 1 in
// gpio1.7 for keypad row0
//
// gpio2.0 for keypad row1
// gpio2.1 for keypad column1
// gpio2.2 for keypad row3
// gpio2.3 for keypad column0
// gpio2.4 for keypad row2
// gpio2.5 for keypad column2
// (only 6 pins @ gpio2)
//
// gpio3.0 for keypad row4
// gpio3.1 for keypad column3
// gpio3.2 for i2c 2nd bus scl
// gpio3.3 for i2c 2nd bus sda
// gpio3.4 for sensor 4 in
// gpio3.5 for 485 de
// gpio3.6 for sensor 3 in
// gpio3.7 for alarm out (to rear panel)
//
// gpio4.[7:0] for vi2 port
//
// gpio5.[7:0] for vi3 port
//

static gpio_dev_t s_gpio_devs[] =
{
    {{0, 7, GPIO_DIR_OUT,  GPIO_PIN_LOW},  GPIO_BUZZR},
    {{3, 7, GPIO_DIR_OUT,  GPIO_PIN_LOW},  GPIO_ALARM},
    {{3, 5, GPIO_DIR_OUT,  GPIO_PIN_LOW},  GPIO_RS485},
    {{0, 5, GPIO_DIR_OUT, GPIO_PIN_HIGH},  GPIO_CDRST},
    {{1, 4, GPIO_DIR_OUT, GPIO_PIN_HIGH},  GPIO_LEDPD},
    {{1, 3, GPIO_DIR_OUT, GPIO_PIN_HIGH},  GPIO_LEDPD},
    {{1, 6,  GPIO_DIR_IN,  GPIO_PIN_LOW},  GPIO_SENSR},
    {{1, 5,  GPIO_DIR_IN,  GPIO_PIN_LOW},  GPIO_SENSR},
    {{3, 6,  GPIO_DIR_IN,  GPIO_PIN_LOW},  GPIO_SENSR},
    {{3, 4,  GPIO_DIR_IN,  GPIO_PIN_LOW},  GPIO_SENSR},
};

int gpio_AckoutFreqSel(unsigned long Freq)
{
    return 0;
}

int gpio_Platform_VerProbe(void)
{
    return GPIO_PROBE_VER0;
}

static void gpio_mode_conf(void)
{
	reg_write32(IO_CONFIG_REG(0), 0x00000002); // 00:VI0HS;01:URXD2;10:GPIO1_3;
	reg_write32(IO_CONFIG_REG(1), 0x00000002); // 00:VI0VS;01:UTXD2;10:GPIO1_4;
	reg_write32(IO_CONFIG_REG(2), 0x00000001); // 0:VI1DAT0;1:GPIO3_0.
	reg_write32(IO_CONFIG_REG(3), 0x00000001); // 0:VI1DAT1;1:GPIO3_1.
	reg_write32(IO_CONFIG_REG(4), 0x00000001); // 0:VI1DAT2;1:GPIO3_2.
	reg_write32(IO_CONFIG_REG(5), 0x00000001); // 0:VI1DAT3;1:GPIO3_3.
	reg_write32(IO_CONFIG_REG(6), 0x00000001); // 0:VI1DAT4;1:GPIO3_4.
	reg_write32(IO_CONFIG_REG(7), 0x00000001); // 0:VI1DAT5;1:GPIO3_5.
	reg_write32(IO_CONFIG_REG(8), 0x00000001); // 0:VI1DAT6;1:GPIO3_6.
	reg_write32(IO_CONFIG_REG(9), 0x00000001); // 0:VI1DAT7;1:GPIO3_7.
	reg_write32(IO_CONFIG_REG(10), 0x00000002); // 00:VI2HS;01:URXD3;10:GPIO1_5;
	reg_write32(IO_CONFIG_REG(11), 0x00000002); // 00:VI2VS;01:UTXD3;10:GPIO1_6;
	reg_write32(IO_CONFIG_REG(12), 0x00000000); // 0:VI2DAT0;1:GPIO4_0.
	reg_write32(IO_CONFIG_REG(13), 0x00000000); // 0:VI2DAT1;1:GPIO4_1.
	reg_write32(IO_CONFIG_REG(14), 0x00000000); // 0:VI2DAT2;1:GPIO4_2.
	reg_write32(IO_CONFIG_REG(15), 0x00000000); // 0:VI2DAT3;1:GPIO4_3.
	reg_write32(IO_CONFIG_REG(16), 0x00000000); // 0:VI2DAT4;1:GPIO4_4.
	reg_write32(IO_CONFIG_REG(17), 0x00000000); // 0:VI2DAT5;1:GPIO4_5.
	reg_write32(IO_CONFIG_REG(18), 0x00000000); // 0:VI2DAT6;1:GPIO4_6.
	reg_write32(IO_CONFIG_REG(19), 0x00000000); // 0:VI2DAT7;1:GPIO4_7.
	reg_write32(IO_CONFIG_REG(20), 0x00000000); // 0:VI3DAT0;1:GPIO5_0.
	reg_write32(IO_CONFIG_REG(21), 0x00000000); // 0:VI3DAT1;1:GPIO5_1.
	reg_write32(IO_CONFIG_REG(22), 0x00000000); // 0:VI3DAT2;1:GPIO5_2.
	reg_write32(IO_CONFIG_REG(23), 0x00000000); // 0:VI3DAT3;1:GPIO5_3.
	reg_write32(IO_CONFIG_REG(24), 0x00000000); // 0:VI3DAT4;1:GPIO5_4.
	reg_write32(IO_CONFIG_REG(25), 0x00000000); // 0:VI3DAT5;1:GPIO5_5.
	reg_write32(IO_CONFIG_REG(26), 0x00000000); // 0:VI3DAT6;1:GPIO5_6.
	reg_write32(IO_CONFIG_REG(27), 0x00000000); // 0:VI3DAT7;1:GPIO5_7.
	reg_write32(IO_CONFIG_REG(28), 0x00000000); // 00:GPIO1_7;01:VOCK;10:SDIOCK;11:SPICK.
	reg_write32(IO_CONFIG_REG(29), 0x00000000); // 00:GPIO2_0;01:VODAT0;10:SDIOCMD;11:SPIDI.
	reg_write32(IO_CONFIG_REG(30), 0x00000000); // 00:GPIO2_1;01:VODAT1;10:SDIODAT0;11:SPIDO.
	reg_write32(IO_CONFIG_REG(31), 0x00000000); // 00:GPIO2_2;01:VODAT2;10:SDIODAT1;11:SPICSN0.
	reg_write32(IO_CONFIG_REG(32), 0x00000000); // 00:GPIO2_3;01:VODAT3;10:SDIODAT2;11:SPICSN1.
	reg_write32(IO_CONFIG_REG(33), 0x00000000); // 00:GPIO2_4;01:VODAT4;10:SDIODAT3;other
	reg_write32(IO_CONFIG_REG(34), 0x00000000); // 00:GPIO2_5;01:VODAT5;10:SDIODETC;other
	reg_write32(IO_CONFIG_REG(35), 0x00000000); // 0:SATALEDN0;1:VODAT6.
	reg_write32(IO_CONFIG_REG(36), 0x00000000); // 0:SATALEDN1;1:VODAT7.
	reg_write32(IO_CONFIG_REG(37), 0x00000001); // 0:SDA;1:GPIO0_0.
	reg_write32(IO_CONFIG_REG(38), 0x00000001); // 0:SCL;1:GPIO0_1.
	reg_write32(IO_CONFIG_REG(39), 0x00000000); // 0:SIO0XFS;1:GPIO0_2.
	reg_write32(IO_CONFIG_REG(40), 0x00000000); // 0:SIO0XCK;1:GPIO0_3.
	reg_write32(IO_CONFIG_REG(41), 0x00000000); // 0:GPIO0_4;1:ACKOUT.
	reg_write32(IO_CONFIG_REG(42), 0x00000000); // 0:GPIO0_5;1:SMICS1N.
	reg_write32(IO_CONFIG_REG(43), 0x00000000); // 0:GPIO0_6;1:NFCS1N.
	reg_write32(IO_CONFIG_REG(44), 0x00000001); // 0:NFRB;1:GPIO0_7.
	reg_write32(IO_CONFIG_REG(45), 0x00000001); // 00:EBIRDYN;01:IRRCV;10:GPIO1_0;other
	reg_write32(IO_CONFIG_REG(46), 0x00000000); // 0:ECOL;1:GPIO1_1.
	reg_write32(IO_CONFIG_REG(47), 0x00000000); // 0:ECRS;1:GPIO1_2.
}
