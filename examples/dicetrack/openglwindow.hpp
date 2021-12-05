#ifndef OPENGLWINDOW_HPP_
#define OPENGLWINDOW_HPP_

#include "abcg.hpp"
#include "dices.hpp"
#include "trackball.hpp"

class OpenGLWindow : public abcg::OpenGLWindow {
 protected:
  void handleEvent(SDL_Event& ev) override;
  void initializeGL() override;
  void paintGL() override;
  void paintUI() override;
  void resizeGL(int width, int height) override;
  void terminateGL() override;

 private:
  int m_viewportWidth{};
  int m_viewportHeight{};

  Dices m_dices;
  int quantity{1};

  std::vector<Vertex> m_vertices;
  std::vector<GLuint> m_indices;
  bool m_hasNormals{false};
  bool m_hasTexCoords{false};
  TrackBall m_trackBallModel;
  TrackBall m_trackBallLight;
  float m_zoom{};

  glm::mat4 m_modelMatrix{1.0f};
  glm::mat4 m_viewMatrix{1.0f};
  glm::mat4 m_projMatrix{1.0f};
 
  float spinSpeed{1.0f}; //Velocidade de rotação dos dados
  // Shaders
  std::vector<const char*> m_shaderNames{"texture", "blinnphong", "phong",
                                         "gouraud", "normal",     "depth"};
  std::vector<GLuint> m_programs;
  int m_currentProgramIndex{};
  int m_mappingMode{};

  // Light and material properties
  glm::vec4 m_lightDir{-1.0f, -1.0f, -1.0f, 0.0f};
  glm::vec4 m_Ia{0.0f, 0.0f, 0.0f, 1.0f};
  glm::vec4 m_Id{1.0f, 1.0f, 1.0f, 1.0f};
  glm::vec4 m_Is{1.0f, 1.0f, 1.0f, 1.0f};

  void computeNormals();
  void update();
  void loadObj(std::string_view path, bool standardize = true);
  void loadDiffuseTexture(std::string_view path);
  void standardize();
};

#endif