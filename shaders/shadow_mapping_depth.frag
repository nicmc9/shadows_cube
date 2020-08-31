#version 330 core

in vec4 FragPos;

uniform vec3 lightPos;
uniform float far_plane;

void main()
{             
   // вычисление расстояния между фрагментом и источником и это в мире
    float lightDistance = length(FragPos.xyz - lightPos);
   // преобразование к интервалу [0, 1] посредством деления на far_plane вот и линейные значения от 0 до 1 в буфере глубины
    lightDistance = lightDistance / far_plane;
    // запись результата в результирующую глубину фрагмента
    gl_FragDepth = lightDistance;
}