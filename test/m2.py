from pynput import mouse, keyboard
import time
import threading
import sys
import os

stop_threads = False

def on_click(x, y, button, pressed):
    global stop_threads
    if pressed:
        print("Clic de souris détecté")
        os.system("ft_lock")
        stop_threads = True

def on_scroll(x, y, dx, dy):
    global stop_threads
    print("Molette de souris détectée")
    os.system("ft_lock")
    stop_threads = True

def on_press(key):
    global stop_threads
    print("Touche pressée, verrouillage")
    os.system("ft_lock")
    stop_threads = True

def execute_ft_lock(delay):
    time.sleep(60 * delay)  # Convertit le délai en minutes
    print(f"Exécution de ft_lock après {delay} minutes")
    os.system("ft_lock")

# Création d'un contrôleur de souris
mouse_controller = mouse.Controller()

# Fonction pour déplacer la souris toutes les minutes
def move_mouse_periodically():
    global last_action
    while True:
        # Déplacement de la souris
        x, y = mouse_controller.position
        mouse_controller.position = (x + 1, y + 1)
        last_action = time.time()  # Mise à jour de l'heure de la dernière action
        time.sleep(120)  # Attend une minute

# Vérification de la présence d'un argument de délai
if len(sys.argv) > 1:
    delay = int(sys.argv[1])
else:
    delay = 120  # Par défaut, le délai est de 120 minutes

# Création et démarrage du thread pour exécuter ft_lock après le délai spécifié
ft_lock_thread = threading.Thread(target=execute_ft_lock, args=(delay,))
ft_lock_thread.daemon = True
ft_lock_thread.start()


# Création et démarrage du thread pour le mouvement périodique de la souris
mouse_thread = threading.Thread(target=move_mouse_periodically)
mouse_thread.start()

# Écouteurs pour surveiller les entrées clavier et souris
with mouse.Listener(on_click=on_click) as click_listener:
    with mouse.Listener(on_scroll=on_scroll) as scroll_listener:
        with keyboard.Listener(on_press=on_press) as keyboard_listener:
            while not stop_threads:
                time.sleep(0.5)  # Attend 0.5 seconde avant de vérifier à nouveau
            os._exit(0)  # Quitte le programme sans attendre la fin des threads
