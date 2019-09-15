#include "cospherecore.h"

CoSphereCore::CoSphereCore()
{

}

CoSphereCore::CoSphereCore(CoNode* pNode,
                           CoCamera *pCamera,
                           CoLight *pLight)
    : CoShapeCore(pNode, pCamera, pLight)
{

}

CoSphereCore::~CoSphereCore()
{

}

void CoSphereCore::initialize()
{

    createObject();
    createShaderProgram();
    setUniformLocation();
    bindObject();

}

void CoSphereCore::paint()
{
    // TODO
}


void CoSphereCore::createObject()
{
    CoShapeCore::createObject();
}

void CoSphereCore::createShaderProgram()
{
    m_pShaderProgram = new CoShaderProgram();
    m_pShaderProgram->AddShaders(EShaderType::eFragment, ":resource/glsl/sphere_frag.glsl");
//    m_pShaderProgram->AddShaders(EShaderType::eGeometry, ":resource/glsl/sphere_geom.glsl");
    m_pShaderProgram->AddShaders(EShaderType::eVertex, ":resource/glsl/sphere_vert.glsl");
    m_pShaderProgram->link();
}

void CoSphereCore::bindObject()
{
    // TODO
}

void CoSphereCore::setUniformLocation()
{
    CoShapeCore::setUniformLocation();
}

