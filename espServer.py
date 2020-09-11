# Libs utilizadas
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from webdriver_manager.chrome import ChromeDriverManager
import time

# Criação da Classe
class Blink:
    def __init__(self):
        # Instância para a busca pelo chrome
        self.driver = webdriver.Chrome(ChromeDriverManager().install())
        
        # O endereço que vai buscar 
        # O endereço no caso foi configurado de acordo com a rede local
        self.driver.get('http://')
        time.sleep(5)

        self.onOff()
       
    def onOff(self):
        try:
            # Vai tentar achar um elemento que aparece depois na página
            field1 = WebDriverWait(self.driver, 3).until(
                EC.visibility_of_element_located((By.XPATH, '/html/body/div/a[1]'))
            )   
            field1.click()

            # Se houve o clique de fato no primeiro elemento e ligou o led
            if field1:
                time.sleep(3)

                # Vai tentar achar o elemento que aparece depois na página
                field2 = WebDriverWait(self.driver, 3).until(
                    EC.visibility_of_element_located((By.XPATH, '/html/body/div/a[2]'))
                )
                field2.click()
                # houve o click desliga o led 
                # espera 2 segundos e saí da página

            time.sleep(2)
        finally:
            self.driver.quit()           
ligar = Blink()