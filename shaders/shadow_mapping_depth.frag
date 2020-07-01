#version 330 core

in vec4 FragPos;

uniform vec3 lightPos;
uniform float far_plane;

void main()
{             
   // ���������� ���������� ����� ���������� � ���������� � ��� � ����
    float lightDistance = length(FragPos.xyz - lightPos);
      // �������������� � ��������� [0, 1] ����������� ������� �� far_plane ��� � �������� �������� �� 0 �� 1 � ������ �������
    lightDistance = lightDistance / far_plane;
      // ������ ���������� � �������������� ������� ���������
    gl_FragDepth = lightDistance;
}