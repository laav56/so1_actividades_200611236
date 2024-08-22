Actividad4

1. Crear el Script
Primero, creo un script que se guardará en /usr/local/bin/.

sudo nano /usr/local/bin/actividad4.sh

Agrego en el script

#!/bin/bash

while true
do
    echo "¡Hola! La fecha y hora actual es: $(date)"
    sleep 1
done

Por último le doy permiso de ejecución.
sudo chmod +x /usr/local/bin/actividad4.sh

2. Crear la Unidad de Servicio systemd
Se crea un archivo de unidad de servicio en /etc/systemd/system/. con el siguiente comando:
sudo nano /etc/systemd/system/actividad4.service

Se agrega el siguiente contenido:

[Unit]
Description=Servicio de saludo infinito

[Service]
ExecStart=/usr/local/bin/actividad4.sh
Restart=always
User=nobody
StandardOutput=journal

[Install]
WantedBy=multi-user.target

3. Habilitar y Iniciar el Servicio
Al finalizar de editar el archivo se habilita el servicio e inicia el mismo con los siguientes comandos:

sudo systemctl enable actividad4.service
sudo systemctl start actividad4.service

4. Verificar el Estado del Servicio
Puedes verificar si el servicio está corriendo correctamente con el comando:

sudo systemctl status actividad4.service






