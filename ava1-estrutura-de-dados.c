#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da lista
typedef struct Node {
    int data; // Dado do nó
    struct Node* next; // Ponteiro para o próximo nó
} Node;

// Função para criar um novo nó
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Função para inserir um nó no final da lista
void insert(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Nó inserido com sucesso!\n");
}

// Função para exibir os elementos da lista
void display(Node* head) {
    if (head == NULL) {
        printf("A lista está vazia!\n");
    } else {
        Node* temp = head;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Função para verificar se a lista está vazia
int isEmpty(Node* head) {
    return (head == NULL);
}

// Função para pesquisar um elemento na lista
int search(Node* head, int key) {
    Node* temp = head;
    int index = 0;
    while (temp != NULL) {
        if (temp->data == key) {
            return index;
        }
        temp = temp->next;
        index++;
    }
    return -1;
}

// Função para remover um elemento da lista
void removeElement(Node** head, int key) {
    Node* temp = *head;
    Node* prev = NULL;
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        printf("Elemento removido com sucesso!\n");
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Elemento não encontrado!\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("Elemento removido com sucesso!\n");
}

// Função principal
int main() {
    Node* head = NULL;
    
    // Menu do programa
    int choice, data;
    while (1) {
        printf("1. Inserir um elemento\n");
        printf("2. Exibir os elementos\n");
        printf("3. Verificar se a lista está vazia\n");
        printf("4. Pesquisar um elemento\n");
        printf("5. Remover um elemento\n");
        printf("0. Sair do programa\n");
        printf("Escolha uma opção: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Digite o elemento a ser inserido: ");
                scanf("%d", &data);
                insert(&head, data);
                break;
            case 2:
                display(head);
                break;
            case 3:
                if (isEmpty(head)) {
                    printf("A lista está vazia!\n");
                } else {
                    printf("A lista não está vazia!\n");
                }
                break;
            case 4:
                printf("Digite o elemento a ser pesquisado: ");
                scanf("%d", &data);
                int index = search(head, data);
                if (index == -1) {
                    printf("Elemento não encontrado!\n");
                } else {
                    printf("Elemento encontrado no índice %d da lista.\n", index);
                }
                break;
            case 5:
                printf("Digite o elemento a ser removido: ");
                scanf("%d", &data);
                removeElement(&head, data);
                break;
            case 0:
                exit(0);
            default:
                printf("Opção inválida!\n");
        }
    }
    
    return 0;
}
