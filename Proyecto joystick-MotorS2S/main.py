import machine
import time
import micropython
import network
from machine import Pin,ADC
from umqtt.simple import MQTTClient

def funcion_callback(topic,msg):        ##funcion que capta el mensaje de adafruit y lo decodifica
    dato = msg.decode("utf-8")          #tambien determina prendido o apagado
    topicrec = topic.decode("utf-8")
    print("Mensaje en topico "+topicrec+": "+dato)
    if topicrec == topic_1 and dato == "Off":
        print ("Apagado")
        enable.value(1)
    elif topicrec == topic_1 and dato == "On":
        print ("Encendido")
        enable.value(0)

ssid = 'Wokwi-GUEST'
wifipassword = ''
   
enable = Pin(8,Pin.OUT)
enable.value(1)

sta_if = network.WLAN(network.STA_IF)          ##Habilitamos wifi en esp32
sta_if.active(True)

sta_if.connect(ssid,wifipassword)
print("Conectando")
while not sta_if.isconnected():
    print('.',end="")
    time.sleep(0.1)
print ("Conectado al wifi")    
print (sta_if.ifconfig())

mqtt_server = 'io.adafruit.com'         ##Datos Adafruit
port = 1883
user = 'CastagnaroBB'                   
password = "aio_KHMB50OpvclF1VkQGT2nTNjPEP9d"   

client_id = 'ProyectoSiete'
topic_1 = 'CastagnaroBB/feeds/joystick'
topic_2 = 'CastagnaroBB/feeds/motorpp'          


paso = Pin(6,Pin.OUT)               
dire = Pin(5,Pin.OUT)
paso.value(1)
dire.value(1)
         ##Establecemos 1 por default para que empiece apagado, solo se prende por wifi
horizontal = ADC(4)

def girarMotor():                   ##Mueve el motor 
    conexionMQTT.subscribe(topic_2)
    paso.value(0)
    pasos=10
    #contador=0
    while pasos>0:
        pasos = pasos - 1
        paso.value(1)
        time.sleep_ms(5)
        paso.value(0)
        time.sleep_ms(5)     
    time.sleep_ms(10)

try:
    conexionMQTT = MQTTClient(client_id, mqtt_server, user=user, password=password,port=int(port)) #conectamos con adafruit
    conexionMQTT.set_callback(funcion_callback)
    conexionMQTT.connect()
    conexionMQTT.subscribe(topic_1)         ##Conexion con el joystick en adafruit
    print("Conectado con Broker MQTT")

except OSError as e:
    print("Fallo la conexion al broker, reiniciando...")
    time.sleep(5)
    machine.reset()

while True:
    try:
        conexionMQTT.check_msg()
        time.sleep_ms(500)
        valHor = horizontal.read()
            
        if valHor>2048:                             ##Lectura del joystick y determina direccion
            dire.value(1)
            conexionMQTT.publish(topic_2,"Derecha") 
        elif valHor<2048: 
            dire.value(0)
            conexionMQTT.publish(topic_2,"Izquierda")
        if valHor!=2048:                            ##Solo se mueve si no esta en el medio
            girarMotor()
            
        
        
    except OSError as e:
        print("Error",e)
        time.sleep(5)
        machine.reset()


    #print("H: "+str(valHor))


