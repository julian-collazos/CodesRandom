# comment push an pop from checker
# add self.inClass = True on the init of the Checker class
 from ast import Return


def visit(self, node: ClassDeclaration, env: Symtab):
     self._add_symbol(node, env)
     if node.sclass:
         value = env.get(node.sclass)
         if value is None:
             print(f'La clase {node.sclass} no esta definida')
            
    env = Symtab(env)
    env.inClass = True
    for meth in node.methods:
        meth.accept(self, env)

# en cparser agregar:
# from checker import Checker
# y al final:
# ast =p.parse(l.tokenize)
# Checker.check(ast)

def visit(self, node: f¿FunDeclaration, env: Symtab):
    self._ad_symbol(node, env)
    env = Symtab(env)
    for param in node.params:
        self._addd_symbol(VarDeclaration(param)) # VarDeclration viene del cast
    for stmt in node.stmts:
        stmt.accept(self, env)
    
def visit(self, node: VarDeclaration, env: Symtab):
    self._ad_symbol(node, env)
    if node.expr:
        node.expr.accept(self, env)
    
def visit(self, node: Block, env: Symtab):
    for stmt in node.stmts:
        stmt.accept(self, env)
    
def visit(self, node: Print, env: Symtab):
    node.expr.accept(self, env)

def visit(self, node: IfStmt, env: Symtab):
    node.test.accept(self, env)
    node.cons.accept(self, env)
    if node.altr:
        node.altr.accept(self, env)

def visit(self, node: WhileStmt, env: Symtab):
    node.test.accept(self, env)
    for stmt in node.body:
        stmt.accept(self, env)

def visit(self, node: Binary, env:Symtab):
    node.left.accept(self, env)
    node.right.accept(self, env)

def visit(self, node: Variable, env:Symtab):
    value = env.get(node.name)
    if value is None:
        print(f'La variable {node.name} no esta definida')

def visit(self, node Assign, env: Symtab):
    node.name.accept(self, env)
    node.expr.accept(self, env)

