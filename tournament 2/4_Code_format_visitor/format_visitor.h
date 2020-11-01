//
// Created by User on 01.11.2020.
//

#ifndef PMI_T_3_H_CPP_TOURNAMENT_2_4_CODE_FORMAT_VISITOR_FORMAT_VISITOR_H_
#define PMI_T_3_H_CPP_TOURNAMENT_2_4_CODE_FORMAT_VISITOR_FORMAT_VISITOR_H_
class FormatVisitor: public BaseVisitor {
 public:
  void Visit(const BaseNode* node) override {
    node->Visit(this);
  }

  void Visit(const ClassDeclarationNode* node) override;
  void Visit(const VarDeclarationNode* node) override;
  void Visit(const MethodDeclarationNode* node) override;

  const std::vector<std::string>& GetFormattedCode() const;
};
#endif //PMI_T_3_H_CPP_TOURNAMENT_2_4_CODE_FORMAT_VISITOR_FORMAT_VISITOR_H_
