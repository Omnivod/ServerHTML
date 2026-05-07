const MAX_STARS = 100;
const stars = [];

const container = document.querySelector('.__bg');
container.innerHTML = '';

for (let i = 0; i < MAX_STARS; i++) {
    const star = document.createElement('div');
    star.classList.add('star');
    
    const x = Math.random() * 100;
    const y = Math.random() * 100;
    
    star.style.left = x + '%';
    star.style.top = y + '%';
    star.style.animationDelay = Math.random() * Math.random() * 12 + 's';
    
    container.appendChild(star);
    stars.push(star);
}
