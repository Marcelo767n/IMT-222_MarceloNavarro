# protocolos de comunicacion 
## UART(universal asynchronous Receiver Transmiter)
- UART (recepcion y transmision asincronica universal)
- admite transmision de datos bidireccional, asincrona y en serie 
- tiene dos lineas de datos, una para transmitir TX y otra para recibir RX, las cuales se utilizan para comunicarse a traves del pin digital 0, pin digital 1 
- la velocidad de transmision de datos de UART  se conoce como tasa BAUD
- el modulo consta de un registro de transmision y de recepcion para almacenar datos. fiel a su naturaleza asincrona, la transmision y la recepcion en un nodo son impulsadas por su generador de reloj local.
- para configurarlo en otras placas se tiene bits de inicio de parada y de final 
## I2C (inter-integrated circuit)
- tiene 2 lineas que son SCL (lineas de reloj en serie)
- tiene multiples estado de velocidad que son 3 
- el modo estandar abarca velocidades de transmicion de hasta 100kbit/s
### ventajas 
- flexible, ya que admite comunicacion multimaestro y multiesclavo 
- simple ya que solo utiliza 2 cables bidireccionales 
- adaptable ya que puede adaptarse a las necesidades de varios dispositivos 
- soporta multiples maestros
### desventajas 
- velocidad mas lenta
- puede volverse complejo a medida que aumenta la cantidad de dispositivos 