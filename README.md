# 📚 Sistema de Gerenciamento de Biblioteca em C

<p align="center">
  <img src="https://img.shields.io/badge/Linguagem-C-blue.svg" alt="C">
  <img src="https://img.shields.io/badge/Status-Conclu%C3%ADdo-brightgreen.svg" alt="Status">
  <img src="https://img.shields.io/badge/Ambiente-Acad%C3%AAmico-purple.svg" alt="Acadêmico">
</p>

## 🔍 Sobre o Projeto
Este projeto é um sistema baseado em terminal desenvolvido em **Linguagem C** como parte da atividade prática (MAPA) para o curso de Análise e Desenvolvimento de Sistemas da **UniCesumar**. O objetivo principal é simular o fluxo de gerenciamento de um acervo técnico de livros de forma estruturada e eficiente.

---

## 🛠️ Funcionalidades principais
O sistema possui um menu interativo que permite realizar as seguintes operações:

* **1. Cadastrar Livro:** Permite a inserção de dados como Código, Título, Autor, Área de estudo, Ano de publicação e Editora.
* **2. Imprimir Todos os Livros:** Exibe na tela a lista completa de todas as obras registradas até o momento.
* **3. Pesquisar por Código:** Realiza uma busca rápida no acervo utilizando o identificador único do livro.
* **4. Ordenar por Ano:** Organiza toda a lista de livros em ordem cronológica crescente utilizando o algoritmo de ordenação **Bubble Sort**.
* **5. Sair:** Finaliza a execução do programa com segurança.

---

## 💻 Conceitos Aplicados
Para a construção deste software, foram colocados em prática conceitos fundamentais de lógica e estrutura de dados:
* **Estruturas (`struct`):** Para a criação do modelo de dados e organização dos atributos do objeto `Livro`.
* **Vetores e Ponteiros:** Manipulação do array do acervo e controle do tamanho dinâmico de registros na memória através de passagem por referência.
* **Algoritmos de Ordenação:** Implementação manual do método de ordenação por bolha (*Bubble Sort*).
* **Tratamento de Entrada:** Uso de buffers de limpeza para evitar falhas de leitura de strings com `fgets` e capturas com `scanf`.

---

## 🚀 Como Executar o Programa

Se quiser rodar o projeto localmente na sua máquina, siga os passos abaixo:

1. **Clonar o repositório:**
   ```bash
   git clone [https://github.com/gabr3ela/Sistema-de-Gerenciamento-de-Biblioteca-em-C.git](https://github.com/gabr3ela/Sistema-de-Gerenciamento-de-Biblioteca-em-C.git)
