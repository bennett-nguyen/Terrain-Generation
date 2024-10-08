#ifndef VBO_HPP
#define VBO_HPP

#include "GL/glew.h"

class VBO {
public:
    VBO();
    ~VBO();
    void bind();
    void unbind();
    void buffer_data(GLsizeiptr size, const void* data, GLenum usage);
    void attrib_pointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer);
    void enable_attrib_array(GLuint index);
    void gen_buffer();
    void delete_buffer();
private:
    GLuint ID;
};

#endif