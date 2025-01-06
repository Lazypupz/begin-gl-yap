
#version 330 core
out vec4 FragColour;
out vec4 frag;
uniform vec4 treeColour;
uniform vec4 trunkColour;
void main() {
    FragColour = treeColour;
    frag = trunkColour;
}
