class Singleton {
  constructor(name) {
    this.name = name;
    this.instance = null;
  }

  getName() {
    return this.name;
  }

  static getInstance(name) {
    if (!this.instance) {
      this.instance = new Singleton(name);
    }
    return this.instance;
  }
};

console.log(Singleton.getInstance('Encounter') === Singleton.getInstance('xingbofeng'));
