
function render(textBox, delay) {
    let i = 0;
    const description = textBox.textContent;
    function iterate() {
        textBox.textContent = description.slice(0, i + 1);
        i++;

        if (i < description.length) {
            setTimeout(iterate, delay);
        }
    }

    iterate();
}

let header = document.querySelector(".header");
render(header, 60);

let cards = document.querySelectorAll(".card-description");

for (let card of cards) {
    render(card, 15);
}

let cardHeaders = document.querySelectorAll(".card-header");

for (let cHead of cardHeaders) {
    render(cHead, 60);
}

let links = document.querySelectorAll("a");

for(let link of links){
    render(link,100);
}