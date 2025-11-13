# Ordenamiento-De-Archivos-Binarios-con-SSORT

El objetivo de este trabajo es ordenar registros almacenados en un archivo binario **sin cargarlos completamente en memoria**, utilizando una versión adaptada del algoritmo **Selection Sort (SSort)**.

El algoritmo trabaja directamente sobre el archivo, leyendo únicamente los registros necesarios y utilizando `fseek` para posicionarse en cualquier parte del archivo. De esta forma, la memoria utilizada es mínima (solo algunos buffers del tamaño del registro), lo cual permite ordenar archivos muy grandes.

Para cada posición del archivo, el algoritmo busca el **mínimo registro** en el resto del archivo mediante comparaciones sucesivas. Cuando encuentra uno más pequeño, guarda ese registro como nuevo mínimo. Al finalizar la búsqueda para esa posición, si el mínimo está en otra ubicación del archivo, se realiza un **intercambio directo (swap)** entre ambos registros utilizando lecturas y escrituras binarias (`fread` y `fwrite`).

Esta técnica es útil cuando no es posible realizar el ordenamiento en memoria por limitaciones de RAM, o cuando se trabaja con archivos de tamaño considerable. Aunque SSort no es el algoritmo más eficiente en tiempo (O(n²)), su implementación sobre archivos es simple, robusta y requiere **memoria constante**, lo que lo hace ideal para este tipo de prácticas y sistemas de archivos.
