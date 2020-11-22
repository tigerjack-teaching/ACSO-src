# Build instructions
  * Bisogna avere installato nel proprio sistema il pacchetto `linux-headers`
  * Non funziona su ambienti emulati (come WSL)
  
  Per generare il modulo:
  * `sudo make modules_install`
  Per installare il modulo
  * `sudo modprobe helloaxo.ko`

  Per generale il modulo localmente, senza inserirlo in nessun percorso conosciuto da `modprobe`:
  * `make modules`
  
  Per osservare il modulo una volta aggiunto dinamicamente con `modprobe` invocare `dmesg`.
