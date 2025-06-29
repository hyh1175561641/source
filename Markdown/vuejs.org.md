Vue 文档是什么?
如果一个人想要去了解一个新的事物, 他就到处去搜集信息, 询问别人, 查阅资料, 把从四面八方搜集到的信息放到一起, 然后整合到一块, 这样做的人不仅仅需要积极主动, 还要有整理和归纳的能力.
那如果这个人比较懒, 或者并不是太积极怎么办呢? 如何才能把 vue 的所有内容塞到对方的脑子里呢? Vue 的开发者经常接到各种各样的问题, 并且耐心的一一解答, 他们把自己收集到的问题和解答整理起来, 把这些想法按照一定顺序排列起来, 然后形成一段内容, 然后在形成文章, 再形成最终的文档. 文档的顺序, 是顺着人性和人对事物的理解程度慢慢递增而来的.

https://vuejs.org/
https://play.vuejs.org/

# Getting Started

## Introduction

https://vuejs.org/guide/introduction.html

本篇文章内容总结: 1 第一段内容介绍了 Vue 的功能及用途, 并用一个简单的例子展现了 Vue 的两大特性 js 决定 HTML 输出, js 变化 DOM 立刻跟着变化. 2 第二段介绍 vue 是渐进式框架, 可根据开发者的需求选择合适的方案整合到自己的项目中. 并且对于初学者或者资深人员都很友好. 3 第三段介绍单文件组件, 把同一个组件的 html css js 压缩到一个文件中. 4 第四段内容介绍 API 风格, 选项式 API 和组合式 API, 选项式 API 是基于组合式 API 实现的, 如果不使用构建工具使用选项式 API, 构建完整应用程序使用组合式 API. 5 如果有疑问可以问 FAQ. 6 提出三种学习路径, 动手练习, 查看文档, 示例代码

Introduction 介绍
You are reading the documentation for Vue 3!
你正在阅读 Vue 3 的文档！
Vue 2 support has ended on Dec 31, 2023. Learn more about Vue 2 EOL https://v2.vuejs.org/eol/.
Vue 2 支持已于 2023 年 12 月 31 日结束。了解有关 Vue 2 EOL 的更多信息。
Upgrading from Vue 2? Check out the Migration Guide https://v3-migration.vuejs.org/.
从 Vue 2 升级？查看迁移指南。

Vue Mastery banner
Learn Vue with video tutorials on VueMastery.com https://www.vuemastery.com/courses/
通过 VueMastery.com 上的视频教程学习 Vue

What is Vue? 什么是 Vue？

Vue (pronounced /vjuː/, like view) is a JavaScript framework for building user interfaces. It builds on top of standard HTML, CSS, and JavaScript and provides a declarative, component-based programming model that helps you efficiently develop user interfaces of any complexity.
Vue（发音为 /vjuː/，类似于 view）是一个用于构建用户界面的 JavaScript 框架。它构建在标准 HTML、CSS 和 JavaScript 之上，并提供基于组件的声明性编程模型，帮助您高效开发任何复杂的用户界面。

Here is a minimal example:

```js
import { createApp, ref } from 'vue'

createApp({
  setup() {
    return {
      count: ref(0)
    }
  }
}).mount('#app')

<div id="app">
  <button @click="count++">
    Count is: {{ count }}
  </button>
</div>
```

Result

The above example demonstrates the two core features of Vue:
上面的例子演示了 Vue 的两个核心特性：
Declarative Rendering: Vue extends standard HTML with a template syntax that allows us to declaratively describe HTML output based on JavaScript state.
声明式渲染：Vue 使用模板语法扩展了标准 HTML，允许我们根据 JavaScript 状态声明式描述 HTML 输出。
Reactivity: Vue automatically tracks JavaScript state changes and efficiently updates the DOM when changes happen.
响应性：Vue 会自动跟踪 JavaScript 状态变化，并在变化发生时有效地更新 DOM。
You may already have questions - don't worry. We will cover every little detail in the rest of the documentation. For now, please read along so you can have a high-level understanding of what Vue offers.
您可能已经有疑问 - 别担心。我们将在文档的其余部分介绍每一个小细节。现在，请继续阅读，以便对 Vue 提供的功能有一个高层次的了解。

Prerequisites 先决条件
The rest of the documentation assumes basic familiarity with HTML, CSS, and JavaScript. If you are totally new to frontend development, it might not be the best idea to jump right into a framework as your first step - grasp the basics and then come back! You can check your knowledge level with these overviews for JavaScript, HTML and CSS if needed. Prior experience with other frameworks helps, but is not required.
本文档的其余部分假定您对 HTML、CSS 和 JavaScript 有基本的了解。如果你对前端开发完全陌生，那么第一步直接进入框架可能不是最好的主意 - 掌握基础知识，然后再回来！如果需要，您可以通过这些 JavaScript、HTML 和 CSS 概述来检查您的知识水平。以前使用其他框架的经验会有所帮助，但这不是必需的。

The Progressive Framework 进步框架
Vue is a framework and ecosystem that covers most of the common features needed in frontend development. But the web is extremely diverse - the things we build on the web may vary drastically in form and scale. With that in mind, Vue is designed to be flexible and incrementally adoptable. Depending on your use case, Vue can be used in different ways:
Vue 是一个框架和生态系统，涵盖了前端开发所需的大多数常见功能。但 Web 是极其多样化的 - 我们在 Web 上构建的东西在形式和规模上可能会有很大差异。考虑到这一点，Vue 被设计为灵活且可逐步采用。根据你的用例，Vue 可以以不同的方式使用：
Enhancing static HTML without a build step 无需构建步骤，渐进式增强静态的 HTML
Embedding as Web Components on any page 在任何页面中作为 Web Components 嵌入
Single-Page Application (SPA) 单页应用 (SPA)
Fullstack / Server-Side Rendering (SSR) 全栈 / 服务端渲染 (SSR)
Jamstack / Static Site Generation (SSG) Jamstack / 静态站点生成 (SSG)
Targeting desktop, mobile, WebGL, and even the terminal 开发桌面端、移动端、WebGL，甚至是命令行终端中的界面

If you find these concepts intimidating, don't worry! The tutorial and guide only require basic HTML and JavaScript knowledge, and you should be able to follow along without being an expert in any of these.
如果您觉得这些概念令人生畏，请不要担心！本教程和指南只需要基本的 HTML 和 JavaScript 知识，您应该能够在不成为任何这些方面的专家的情况下跟上。

If you are an experienced developer interested in how to best integrate Vue into your stack, or you are curious about what these terms mean, we discuss them in more detail in Ways of Using Vue https://vuejs.org/guide/extras/ways-of-using-vue.html.
如果你是一个有经验的开发者, 有趣的在如何最佳整合 Vue 在你的栈中, 或者你是好奇关于这些期限意思, 我们描述它们在更多详细在 Ways of Using Vue 中.

experienced 有经验的
interested 感兴趣的
integrate 整合
stack 堆栈
curious 好奇的
terms 期限
mean 意思是
discuss 商量

Despite the flexibility, the core knowledge about how Vue works is shared across all these use cases. Even if you are just a beginner now, the knowledge gained along the way will stay useful as you grow to tackle more ambitious goals in the future. If you are a veteran, you can pick the optimal way to leverage Vue based on the problems you are trying to solve, while retaining the same productivity. This is why we call Vue "The Progressive Framework": it's a framework that can grow with you and adapt to your needs.
尽管很灵活, 核心知识关于如何 Vue 工作被共享通过所有这些用例. 甚至如果你只是初学者, 知识获取独自的方式将保持有用的作为你成长去解决更多雄心目标在未来. 如果你是经验丰富的, 你可以选择最佳方式去影响 Vue 基于在问题你尝试解决, 保持相同的生产效率. 这是为什么我们叫 Vue 渐进式框架, 它是框架可以伴你成长和适应你的需求.

despite 尽管
flexibility 灵活
case 实例 例子
even 甚至
gained 获得
tackle 解决
ambitious 雄心勃勃的
goal 目标
future 将来
feature 特色
veteran 经验丰富的
pick 选择
optimal 最佳的
leverage 影响力
solve 解决
retaining 固定的 保持
productivity 生产率
progressive 进步的
adapt 适应

Single-File Components 单文件组件
In most build-tool-enabled Vue projects, we author Vue components using an HTML-like file format called Single-File Component (also known as _.vue files, abbreviated as SFC). A Vue SFC, as the name suggests, encapsulates the component's logic (JavaScript), template (HTML), and styles (CSS) in a single file. Here's the previous example, written in SFC format:
在大多数可行构建工具 Vue 项目, 我们创作 Vue 组件使用一个类似 HTML 文件格式被叫做单文件组件(也是已知的作为_.vue 文件,缩写为 SFC). 一个 VueSFC, 由名字建议, 压缩了组建的逻辑模板和样式在一个单个文件. 这里是上一个例子, 写在 SFC 格式:

enabled 能够
author 作者
abbreviated 缩写
suggests 建议
encapsulates 压缩概括
logic 逻辑
previous 上一次

```vue
<script setup>
import { ref } from "vue";
const count = ref(0);
</script>

<template>
  <button @click="count++">Count is: {{ count }}</button>
</template>

<style scoped>
button {
  font-weight: bold;
}
</style>
```

SFC is a defining feature of Vue and is the recommended way to author Vue components if your use case warrants a build setup. You can learn more about the how and why of SFC https://vuejs.org/guide/scaling-up/sfc in its dedicated section - but for now, just know that Vue will handle all the build tools setup for you.
SFC 是一个典型的特性 Vue 并且是被推荐的方式去编写 Vue 组件, 如果你使用案例许可一个构建计划. 你可以了解更多关于如何或为什么 SFC 在他的专门部分 但是现在, 只需要知道 Vue 将处理所有构建工具设置为你.

defining 典型的
feature 特性
recommended 被推荐的
author 编写
case 例子 案例
warrants 许可证
setup 设置
dedicated 专心的 献身
section 部分
handle 手柄 把手

API Styles API 样式
Vue components can be authored in two different API styles: Options API and Composition API.
Vue 组件可以被编写用两个不同 API 风格: 选项 API 和组合 API.

Options API 可选 API
With Options API, we define a component's logic using an object of options such as data, methods, and mounted. Properties defined by options are exposed on this inside functions, which points to the component instance:
使用选项 API, 我们定义一个组件逻辑使用一个对象选项比如数据,方法,和挂载. 属性定义通过选项被公开在这个内部函数, 指向到组件实例:

```vue
<script>
export default {
  // Properties returned from data() become reactive state
  // 属性返回从data() 成为反应状态
  // and will be exposed on `this`. 将被公开在this
  data() {
    return {
      count: 0,
    };
  },

  // Methods are functions that mutate state and trigger updates.
  // 方法是函数 转换状态和触发器更新
  // They can be bound as event handlers in templates.
  // 他们可以绑定作为事件处理程序在模板里.
  methods: {
    increment() {
      this.count++;
    },
  },

  // Lifecycle hooks are called at different stages
  // 生命周期钩子被调用在不同阶段
  // of a component's lifecycle.
  // 组件的生命周期
  // This function will be called when the component is mounted.
  // 这个函数将被命名当组件被挂载.
  mounted() {
    console.log(`The initial count is ${this.count}.`);
  },
};
</script>

<template>
  <button @click="increment">Count is: {{ count }}</button>
</template>
```

initial 最初的
increment 增量

Composition API 组合式 API
With Composition API, we define a component's logic using imported API functions. In SFCs, Composition API is typically used with script setup https://vuejs.org/api/sfc-script-setup. The setup attribute is a hint that makes Vue perform compile-time transforms that allow us to use Composition API with less boilerplate. For example, imports and top-level variables / functions declared in script setup are directly usable in the template.
使用组合式 API, 我们定义组件的逻辑使用导入 API 函数. 用 SFC, 组合式 API 是通常使用带脚本设置. 设置属性是一个暗示使 Vue 指向编译时变换允许我们去使用组合式 API 带更少的样板文件. 比如, 导入和顶级变量函数声明在脚本设置是直接可用的在模板里.

perform 执行

Here is the same component, with the exact same template, but using Composition API and script setup instead:
这里是相同的组件, 带准确的相同模板, 但是使用组合式 API 和脚本设置实例:

```vue
<script setup>
import { ref, onMounted } from "vue";

// reactive state 反应状态
const count = ref(0);

// functions that mutate state and trigger updates 函数转换状态和触发更新
function increment() {
  count.value++;
}

// lifecycle hooks
onMounted(() => {
  console.log(`The initial count is ${count.value}.`);
});
</script>

<template>
  <button @click="increment">Count is: {{ count }}</button>
</template>
```

Which to Choose? 哪个选择?
Both API styles are fully capable of covering common use cases. They are different interfaces powered by the exact same underlying system. In fact, the Options API is implemented on top of the Composition API! The fundamental concepts and knowledge about Vue are shared across the two styles.
两者 API 样式是充分地能干的覆盖常见用例. 他们是不同的接口驱动通过完全相同底层系统. 在事实上, 选项式 API 被实现在之上组合式 API! 基本概念和知识关于 Vue 被共享穿过两种风格.

The Options API is centered around the concept of a "component instance" (this as seen in the example), which typically aligns better with a class-based mental model for users coming from OOP language backgrounds. It is also more beginner-friendly by abstracting away the reactivity details and enforcing code organization via option groups.
选项式 API 是被集中在周围概念一个组件实例(这个示例所示), 通常校准更好带基于类的精神模型 为用户带来从面向对象语言背景. 它也是更适合初学者通过抽象化反应性详情和强制执行代码组织通过选项组合.

centered 集中
around 周围
typically 通常
aligns 校准一致
based 基础
mental 精神的
friendly 亲切的
abstracting 提取的
reactivity 反应性
details 详情
enforcing 强制执行
organization 组织
via 通过

The Composition API is centered around declaring reactive state variables directly in a function scope and composing state from multiple functions together to handle complexity. It is more free-form and requires an understanding of how reactivity works in Vue to be used effectively. In return, its flexibility enables more powerful patterns for organizing and reusing logic.
组合式 API 被集中周围声明式反应性状态变量直接地在函数范围和构成状态从多重的函数共同去应对复杂性. 它是更多独创和需要一个理解如果反应性工作在 Vue 高效使用. 作为回应, 它的灵活性提供了更强大的模式为组织和重用逻辑.

You can learn more about the comparison between the two styles and the potential benefits of Composition API in the Composition API FAQ https://vuejs.org/guide/extras/composition-api-faq.
你可以了解更多关于比较在两种样式和并且潜在益处组合式 API 在组合式 API FAQ.

comparison 比较
potential 潜在的
benefits 益处

If you are new to Vue, here's our general recommendation: 如果你新对 Vue, 这里是我们一般建议
For learning purposes, go with the style that looks easier to understand to you. Again, most of the core concepts are shared between the two styles. You can always pick up the other style later.
为了学习的目的, 选择风格看着容易去理解去你. 再次, 更多核心概念被分享在两种风格. 你可以经常捡起另一种风格.
For production use: 为生产使用
Go with Options API if you are not using build tools, or plan to use Vue primarily in low-complexity scenarios, e.g. progressive enhancement.
伴随选项式 API 如果你没有构建工具, 或者计划去使用 Vue 首先用低复杂性方案, 比如逐步增强.
Go with Composition API + Single-File Components if you plan to build full applications with Vue.
伴随组合式 API 加单文件组件, 如果你计划去构建完整的应用程序用 Vue

recommendation 建议

You don't have to commit to only one style during the learning phase. The rest of the documentation will provide code samples in both styles where applicable, and you can toggle between them at any time using the API Preference switches at the top of the left sidebar.
你不能去承诺去唯一样式在学习阶段. 休息文档将提供代码样品在风格合适的时候, 你可以切换他们 不同任何时间使用 API 偏爱切换在顶端左工具栏.

Still Got Questions? 任然有问题
Check out our FAQ. https://vuejs.org/about/faq

Pick Your Learning Path 捡起你的学习方式
Different developers have different learning styles. Feel free to pick a learning path that suits your preference - although we do recommend going over all of the content, if possible!
不同开发者有不同学习风格. 感到自由去捡起学习路径符合你的喜好 尽管我们建议尽可能浏览所有内容, 如果可行

suits 一套
preference 喜好
recommend 推荐
going 离去
over 结束
content 内容

Try the Tutorial. For those who prefer learning things hands-on.
尝试教程. 为那些喜欢了解事情动手.
Read the Guide. The guide walks you through every aspect of the framework in full detail.
阅读向导. 向导走向你穿过每个层面框架的在完整详情中.
Check out the Examples. Explore examples of core features and common UI tasks.
检查这些案例. 导出例子中心特征和共同 UI 工作.

prefer 更喜欢
walks 步行
through 穿过
aspect 层面
detail 详述
explore 探讨
features 特征
common 常见的
tasks 工作

## Quick Start

https://vuejs.org/guide/quick-start.html

Quick Start 快速开始
​
Try Vue Online 尝试 Vue 在线
​To quickly get a taste of Vue, you can try it directly in our Playground.
快速地得到任务 Vue 的, 你可以尝试它直接在我们的演练场.
If you prefer a plain HTML setup without any build steps, you can use this JSFiddle https://jsfiddle.net/ as your starting point.
如果你更喜欢简单 HTML 设置不带任何构建步骤, 你可以使用这个 JSFiddle 作为你的起点.
If you are already familiar with Node.js and the concept of build tools, you can also try a complete build setup right within your browser on StackBlitz https://stackblitz.com/.
如果你已经熟悉带 Node.js 和概念构建工具, 你可以也尝试一个完整的构建设置正确的在你的浏览器内在 StackBlitz.

prefer 更喜欢
plain 简单
concept 概念
within 在内

Creating a Vue Application 创建 Vue 应用程序
​Prerequisites 先决条件
Familiarity with the command line 熟悉命令行
Install Node.js https://nodejs.org/ version 18.3 or higher
安装 Node.js 版本 18.3 或更高

In this section we will introduce how to scaffold a Vue Single Page Application on your local machine. The created project will be using a build setup based on Vite https://vite.dev/ and allow us to use Vue Single-File Components (SFCs) https://vuejs.org/guide/scaling-up/sfc.html.
在这部分我们将介绍如何脚手架一个 Vue 单页面应用程序在你的本地机器. 创造项目将使用一个构建步骤基于 Vite 和允许我们去使用 Vue 单文件组件.

introduce 介绍
scaffold 脚手架
created 创造

Make sure you have an up-to-date version of Node.js https://nodejs.org/en installed and your current working directory is the one where you intend to create a project. Run the following command in your command line (without the $ sign):
确信你有一个现代版本 Node.js 被安装并且你当前工作目录是一个你打算去创建一个项目. 运行下面命令在你命令行(不带$符号)

up-to-date 现代的
current 当前的
intend 打算

```npm
$ npm create vue@latest

```

This command will install and execute create-vue https://github.com/vuejs/create-vue, the official Vue project scaffolding tool. You will be presented with prompts for several optional features such as TypeScript and testing support:
这个命令将按照和执行创建 Vue, 官方 Vue 项目脚手架工具. 你将被提出带提示为几个选项特点, 比如 TypeScript 和测试支持:

execute 执行
official 官方的
scaffolding 脚手架组
presented 提出
prompts 鼓励提示
several 几个的
optional 随意的
prettier 非常漂亮
quality 质量
extension 延申

```bash
✔ Project name: … <your-project-name> 项目名字
✔ Add TypeScript? … No / Yes 添加TypeScript
✔ Add JSX Support? … No / Yes 添加JSX Support
✔ Add Vue Router for Single Page Application development? … No / Yes 添加Vue路由为单网页应用程序开发
✔ Add Pinia for state management? … No / Yes 添加Pinia为状态管理
✔ Add Vitest for Unit testing? … No / Yes 添加Vitest为单元测试
✔ Add an End-to-End Testing Solution? … No / Cypress / Nightwatch / Playwright 添加一个端对端测试方案
✔ Add ESLint for code quality? … No / Yes 添加ESLint为代码质量
✔ Add Prettier for code formatting? … No / Yes 添加漂亮为代码格式
✔ Add Vue DevTools 7 extension for debugging? (experimental) … No / Yes 添加Vue开发工具7拓展为调试(实验的)

Scaffolding project in ./<your-project-name>... 脚手架项目在
Done. 完成
```

If you are unsure about an option, simply choose No by hitting enter for now. Once the project is created, follow the instructions to install dependencies and start the dev server:
如果你不确定关于一个选项, 仅仅选择 No 通过敲击 enter 健现在. 一次项目被创建, 跟随介绍去安装依赖和开启 dev 服务:

```npm
$ cd <your-project-name>
$ npm install
$ npm run dev
```

option 选项
simply 仅仅
hitting 打击
instructions 指示

You should now have your first Vue project running! Note that the example components in the generated project are written using the Composition API and `<script setup>`, rather than the Options API. Here are some additional tips:
你应该现在有你第一个 Vue 项目运行! 注意例子组件在产生项目被写使用组合式 API 和, 而不是选项式 API. 这里有一些附加提示:
The recommended IDE setup is Visual Studio Code https://code.visualstudio.com/ + Vue - Official extension. If you use other editors, check out the IDE support section.
推荐 IDE 设置是 VS code + Vue 官方插件. 如果你使用其他编辑器, 检查 IDE 支持部分.
More tooling details, including integration with backend frameworks, are discussed in the Tooling Guide https://vuejs.org/guide/scaling-up/tooling.html.
许多工具详情, 安装集成带后台框架, 被讨论在工具向导.
To learn more about the underlying build tool Vite, check out the Vite docs https://vite.dev/.
去了解更多关于底层构建工具 Vite, 查看 Vlite 文档.
If you choose to use TypeScript, check out the TypeScript Usage Guide https://vuejs.org/guide/typescript/overview.html.
如果你选择去使用 TypeScript, 查看 TypeScript 使用指南.

components 部件
generated 产生引起
rather 相当地
additional 附加的额外的
tips 尖端
recommended 被推荐的
editors 编辑
details 详细的
integration 整合
backend 后台
discussed 讨论
underlying 根本的潜在的
usage 使用

When you are ready to ship your app to production, run the following:
当你准备去运输你应用程序到生产环境, 运行下面命令

```npm
$ npm run build
```

This will create a production-ready build of your app in the project's ./dist directory. Check out the Production Deployment Guide https://vuejs.org/guide/best-practices/production-deployment.html to learn more about shipping your app to production.
这将创建一个生产就绪构建你应用程序在项目的./dist 目录. 查看生产部署向导去了解更多关于运输你应用程序到生产中.

create 创建
production-ready 生产就绪
production 生产
deployment 部署
shipping 运输

Using Vue from CDN 使用 Vue 来自 CDN
You can use Vue directly from a CDN via a script tag: 你可以使用 Vue 直接地从 CDN

```html
<script src="https://unpkg.com/vue@3/dist/vue.global.js"></script>
```

Here we are using unpkg https://unpkg.com/, but you can also use any CDN that serves npm packages, for example jsdelivr https://www.jsdelivr.com/package/npm/vue or cdnjs https://cdnjs.com/libraries/vue. Of course, you can also download this file and serve it yourself.
这里我们使用 unpkg, 但你也可以使用任何 CND 服务 npm 包, 为例子 jsdelivr 或 cdnjs. 当然, 你也可以下载这个文件和服务他自己.

When using Vue from a CDN, there is no "build step" involved. This makes the setup a lot simpler, and is suitable for enhancing static HTML or integrating with a backend framework. However, you won't be able to use the Single-File Component (SFC) syntax.
​ 当使用 Vue 从 CDN, 这里是没有构建步骤参与. 这使设置大量简易的, 并且是舒适的为增强静态 HTML 或集成后端框架. 然而, 你将不能够使用单文件组件语法.

involved 参与
suitable 合适的
enhancing 增强
integrating 合并

Using the Global Build 使用全局构建
The above link loads the global build of Vue, where all top-level APIs are exposed as properties on the global Vue object. Here is a full example using the global build:
上面链接加载全局 Vue 构建, 所有顶级 API 公开作为属性在全局 Vue 对象. 这里有完整案例使用全局构建:

above 上面
loads 负载
exposed 无遮蔽的
properties 特性

```html
<script src="https://unpkg.com/vue@3/dist/vue.global.js"></script>
<div id="app">{{ message }}</div>
<script>
  const { createApp, ref } = Vue;
  createApp({
    setup() {
      const message = ref("Hello vue!");
      return {
        message,
      };
    },
  }).mount("#app");
</script>
```

CodePen Demo > https://codepen.io/

TIP 提示
Many of the examples for Composition API throughout the guide will be using the `<script setup>` syntax, which requires build tools. If you intend to use Composition API without a build step, consult the usage of the setup() option https://vuejs.org/api/composition-api-setup.html.
许多例子为组件式 API 通过向导将使用 setup 语法, 需要构建工具. 如果你打算去使用组件式 API 不带构建步骤, 资讯使用 setup 选项.

intend 打算

Using the ES Module Build 使用 ES 模块构建

Throughout the rest of the documentation, we will be primarily using ES modules https://developer.mozilla.org/en-US/docs/Web/JavaScript/Guide/Modules syntax. Most modern browsers now support ES modules natively, so we can use Vue from a CDN via native ES modules like this:
遍及其余文档, 我们将主要使用 ES 模块语法. 大部分现代浏览器新支持 ES 模块原生, 所以我们可以使用 Vue 从 CDN 通过原生的 ES 模块类似这样.

rest 休息其余

```html
<div id="app">{{ message }}</div>

<script type="module">
  import {
    createApp,
    ref,
  } from "https://unpkg.com/vue@3/dist/vue.esm-browser.js";

  createApp({
    setup() {
      const message = ref("Hello Vue!");
      return {
        message,
      };
    },
  }).mount("#app");
</script>
```

Notice that we are using `<script type="module">`, and the imported CDN URL is pointing to the ES modules build of Vue instead.
提示: 我们使用 script module, 并且导入 CDN 地址是指向取代 Vue 构建的 ES 模块
CodePen Demo >

Enabling Import maps 启用导入映射
In the above example, we are importing from the full CDN URL, but in the rest of the documentation you will see code like this:
在上个例子, 我们导入来自完整 CDN URL, 但是在其余文档你将看见代码像这样:

```js
import { createApp } from "vue";
```

We can teach the browser where to locate the vue import by using Import Maps https://caniuse.com/import-maps:
我们可以训练浏览器定位到哪里 vue 导入通过使用导入映射

```html
<script type="importmap">
  {
    "imports": {
      "vue": "https://unpkg.com/vue@3/dist/vue.esm-browser.js"
    }
  }
</script>

<div id="app">{{ message }}</div>

<script type="module">
  import { createApp, ref } from "vue";

  createApp({
    setup() {
      const message = ref("Hello Vue!");
      return {
        message,
      };
    },
  }).mount("#app");
</script>
```

CodePen Demo >

You can also add entries for other dependencies to the import map - but make sure they point to the ES modules version of the library you intend to use.
你也可以添加进入为其他依赖去导入映射 - 但是确保他们指向 ES 模块版本的库你打算去使用.

Import Maps Browser Support 导入映射浏览器支持
Import Maps is a relatively new browser feature. Make sure to use a browser within its support range https://caniuse.com/import-maps. In particular, it is only supported in Safari 16.4+.
导入映射是一个相当新浏览器功能. 确保去使用一个浏览器里面支持范围. 尤其, 它是仅仅被支持在 Safari1 6.4+.

Notes on Production Use 注意在生产使用中
The examples so far are using the development build of Vue - if you intend to use Vue from a CDN in production, make sure to check out the Production Deployment Guide https://vuejs.org/guide/best-practices/production-deployment.html#without-build-tools.
这个例子目前为止正在使用在 vue 的开发构建 - 如果你打算去使用 Vue 从 CDN 用于生产, 确保去检查产品部署指南.
While it is possible to use Vue without a build system, an alternative approach to consider is using vuejs/petite-vue https://github.com/vuejs/petite-vue​ that could better suit the context where jquery/jquery https://github.com/jquery/jquery (in the past) or alpinejs/alpine https://github.com/alpinejs/alpine (in the present) might be used instead.
当可能使用 Vue 时不带构建系统, 一个可替代的方法去考虑使用 vuejs/petite-vue, 可以更好套件上下文是 jquery/jquery(过去)或者 alpinejs/alpine(现在)可能替换使用.

Splitting Up the Modules 拆分模块
As we dive deeper into the guide, we may need to split our code into separate JavaScript files so that they are easier to manage. For example:
当我们潜入更深在指南中, 我们可能需要拆分我们代码到单独的 js 文件, 因此他们是更容易去管理, 比如:

```html
<!-- index.html -->
<div id="app"></div>

<script type="module">
  import { createApp } from "vue";
  import MyComponent from "./my-component.js";

  createApp(MyComponent).mount("#app");
</script>
```

```js
// my-component.js
import { ref } from "vue";
export default {
  setup() {
    const count = ref(0);
    return { count };
  },
  template: `<div>Count is: {{ count }}</div>`,
};
```

If you directly open the above index.html in your browser, you will find that it throws an error because ES modules cannot work over the file:// protocol, which is the protocol the browser uses when you open a local file.
如果你直接打开上面的 index.html 用你的浏览器, 你会发现它抛出一个错误因为 ES 模块不会工作在 file:// 协议上, 这个协议是浏览器使用当你打开本地文件
throws 扔, 丢, 抛出

Due to security reasons, ES modules can only work over the http:// protocol, which is what the browsers use when opening pages on the web. In order for ES modules to work on our local machine, we need to serve the index.html over the http:// protocol, with a local HTTP server.
由于安全原因, ES 模块仅仅工作在 http 协议上, 浏览器用什么当打开页面在 web 上. 按顺序为 ES 模块去工作在我们本地机器, 我们需要去服务 index.html 在 http 协议上, 附带本地 HTTP 服务.
due 由于
reasons 原因

To start a local HTTP server, first make sure you have Node.js https://nodejs.org/en/ installed, then run npx serve from the command line in the same directory where your HTML file is. You can also use any other HTTP server that can serve static files with the correct MIME types.
去开启本地 HTTP 服务器, 首先确保你 Node.js 被安装, 然后运行 npx serve 从命令行在相同目录你 HTML 文件在的位置. 你也可以使用任何其他 HTTP 服务可以服务静态文件带适当的 MIME 类型

You may have noticed that the imported component's template is inlined as a JavaScript string. If you are using VS Code, you can install the es6-string-html https://marketplace.visualstudio.com/items?itemName=Tobermory.es6-string-html extension and prefix the strings with a /_html_/ comment to get syntax highlighting for them.
你或许注意到导入组件的模板是内联的 js 字符串. 如果你正在用 VScode, 你可以安装 es6-string-html 拓展, 并且前缀字符串带注释去得到语法高亮为他们.

Next Steps 下一步
If you skipped the Introduction, we strongly recommend reading it before moving on to the rest of the documentation.
如果你跳过了简介, 我们强烈建议阅读它在翻阅其他文档之前.
Continue with the Guide. The guide walks you through every aspect of the framework in full detail. 继续指南. 这个指南直走每个方面框架的在丰富的细节.
Try the Tutorial. For those who prefer learning things hands-on. 尝试教程, 这个更喜欢了解事物动手的.
Check out the Examples. Explore examples of core features and common UI tasks. 查看示例. 研究示例核心功能并且常见 UI 任务.
strongly 强烈的
recommend 推荐
aspect 方面
detail 细节
prefer 更喜欢
hands-on 动手的
explore 探讨

# Essentials

## Creating an Application

https://vuejs.org/guide/essentials/application.html

Creating a Vue Application 创建一个 Vue 应用程序

The application instance 应用程序实例
​Every Vue application starts by creating a new application instance with the createApp function:
每个应用程序开始通过创建一个新的应用程序实例带 createApp 函数

```js
import { createApp } from "vue";
const app = createApp({
  /* root component options */
});
```

The Root Component 根组件
The object we are passing into createApp is in fact a component. Every app requires a "root component" that can contain other components as its children.
对象我们是通过 createApp 事实上一个组件. 每个 app 需要一个根组件可以包含其他组件和它的子组件
If you are using Single-File Components, we typically import the root component from another file:
如果你使用单文件组件, 我们通常导入根组件从其他文件

```js
import { createApp } from "vue";
// import the root component App from a single-file component.
import App from "./App.vue";
const app = createApp(App);
```

While many examples in this guide only need a single component, most real applications are organized into a tree of nested, reusable components. For example, a Todo application's component tree might look like this:
当许多例子在这个向导仅需要一个单组件, 大部分真实的应用程序被组织在一个嵌套的重复利用的树组件中. 比如一个 Todo 应用程序组件树或许看起来像这样:

```
App (root component)
├─ TodoList
│  └─ TodoItem
│     ├─ TodoDeleteButton
│     └─ TodoEditButton
└─ TodoFooter
   ├─ TodoClearButton
   └─ TodoStatistics
```

In later sections of the guide, we will discuss how to define and compose multiple components together. Before that, we will focus on what happens inside a single component.
在向导之后的部分中, 我们将讨论如何定义和组合成倍的的组件. 在这之前, 我们将聚焦在单个组件中发生什么.

Mounting the App 挂载 app
An application instance won't render anything until its .mount() method is called. It expects a "container" argument, which can either be an actual DOM element or a selector string:
一个应用程序实例不会提供任何东西直到它的.mount()方法被调用. 它期望一个容器参数, 可以是实际的 DOM 元素或一个选择器字符串:

```html
<div id="app"></div>
```

```js
app.mount("#app");
```

The content of the app's root component will be rendered inside the container element. The container element itself is not considered part of the app.
应用程序的根组件内容将被渲染到容器元素中. 容器元素本身不被视为应用程序的一部分.

The .mount() method should always be called after all app configurations and asset registrations are done. Also note that its return value, unlike the asset registration methods, is the root component instance instead of the application instance.
mount 方法应该经常被调用在所有应用程序配置和资产注册完成之后. 也要注意它的返回值, 不同于资产注册方法, 是根组件实例, 而不是应用组件实例.

In-DOM Root Component Template 在 DOM 根组件模板
The template for the root component is usually part of the component itself, but it is also possible to provide the template separately by writing it directly inside the mount container:

```html
<div id="app">
  <button @click="count++">{{ count }}</button>
</div>
```

```js
import { createApp } from "vue";
const app = createApp({
  data() {
    return {
      count: 0,
    };
  },
});
app.mount("#app");
```

Vue will automatically use the container's innerHTML as the template if the root component does not already have a template option.

In-DOM templates are often used in applications that are using Vue without a build step https://vuejs.org/guide/quick-start.html#using-vue-from-cdn. They can also be used in conjunction with server-side frameworks, where the root template might be generated dynamically by the server.
App Configurations
​

The application instance exposes a .config object that allows us to configure a few app-level options, for example, defining an app-level error handler that captures errors from all descendant components:
js

app.config.errorHandler = (err) => {
/_ handle error _/
}

The application instance also provides a few methods for registering app-scoped assets. For example, registering a component:
js

app.component('TodoDeleteButton', TodoDeleteButton)

This makes the TodoDeleteButton available for use anywhere in our app. We will discuss registration for components and other types of assets in later sections of the guide. You can also browse the full list of application instance APIs in its API reference https://vuejs.org/api/application.html.

Make sure to apply all app configurations before mounting the app!
Multiple application instances
​

You are not limited to a single application instance on the same page. The createApp API allows multiple Vue applications to co-exist on the same page, each with its own scope for configuration and global assets:
js

const app1 = createApp({
/_ ... _/
})
app1.mount('#container-1')

const app2 = createApp({
/_ ... _/
})
app2.mount('#container-2')

If you are using Vue to enhance server-rendered HTML and only need Vue to control specific parts of a large page, avoid mounting a single Vue application instance on the entire page. Instead, create multiple small application instances and mount them on the elements they are responsible for.

// http://localhost:5173
// http://127.0.0.1:5173
// http://127.0.0.1:5173

## Template Syntax

https://vuejs.org/guide/essentials/template-syntax.html

Template Syntax
​

Vue uses an HTML-based template syntax that allows you to declaratively bind the rendered DOM to the underlying component instance's data. All Vue templates are syntactically valid HTML that can be parsed by spec-compliant browsers and HTML parsers.

Under the hood, Vue compiles the templates into highly-optimized JavaScript code. Combined with the reactivity system, Vue can intelligently figure out the minimal number of components to re-render and apply the minimal amount of DOM manipulations when the app state changes.

If you are familiar with Virtual DOM concepts and prefer the raw power of JavaScript, you can also directly write render functions https://vuejs.org/guide/extras/render-function.html instead of templates, with optional JSX support. However, do note that they do not enjoy the same level of compile-time optimizations as templates.

Text Interpolation
​

The most basic form of data binding is text interpolation using the "Mustache" syntax (double curly braces):
template

<span>Message: {{ msg }}</span>

The mustache tag will be replaced with the value of the msg property from the corresponding component instance https://vuejs.org/guide/essentials/reactivity-fundamentals.html#declaring-reactive-state. It will also be updated whenever the msg property changes.

Raw HTML
​

The double mustaches interpret the data as plain text, not HTML. In order to output real HTML, you will need to use the v-html directive https://vuejs.org/api/built-in-directives.html#v-html:

```template
<p>Using text interpolation: {{ rawHtml }}</p>
<p>Using v-html directive: <span v-html="rawHtml"></span></p>
```

Using text interpolation: <span style="color: red">This should be red.</span>
Using v-html directive: This should be red.

Here we're encountering something new. The v-html attribute you're seeing is called a directive. Directives are prefixed with v- to indicate that they are special attributes provided by Vue, and as you may have guessed, they apply special reactive behavior to the rendered DOM. Here, we're basically saying "keep this element's inner HTML up-to-date with the rawHtml property on the current active instance."

The contents of the span will be replaced with the value of the rawHtml property, interpreted as plain HTML - data bindings are ignored. Note that you cannot use v-html to compose template partials, because Vue is not a string-based templating engine. Instead, components are preferred as the fundamental unit for UI reuse and composition.

Security Warning

Dynamically rendering arbitrary HTML on your website can be very dangerous because it can easily lead to XSS vulnerabilities https://en.wikipedia.org/wiki/Cross-site_scripting. Only use v-html on trusted content and never on user-provided content.
Attribute Bindings
​

Mustaches cannot be used inside HTML attributes. Instead, use a v-bind directive https://vuejs.org/api/built-in-directives.html#v-bind:
template

<div v-bind:id="dynamicId"></div>

The v-bind directive instructs Vue to keep the element's id attribute in sync with the component's dynamicId property. If the bound value is null or undefined, then the attribute will be removed from the rendered element.
Shorthand
​

Because v-bind is so commonly used, it has a dedicated shorthand syntax:
template

<div :id="dynamicId"></div>

Attributes that start with : may look a bit different from normal HTML, but it is in fact a valid character for attribute names and all Vue-supported browsers can parse it correctly. In addition, they do not appear in the final rendered markup. The shorthand syntax is optional, but you will likely appreciate it when you learn more about its usage later.

    For the rest of the guide, we will be using the shorthand syntax in code examples, as that's the most common usage for Vue developers.

Same-name Shorthand
​

    Only supported in 3.4+

If the attribute has the same name with the JavaScript value being bound, the syntax can be further shortened to omit the attribute value:
template

<!-- same as :id="id" -->
<div :id></div>

<!-- this also works -->
<div v-bind:id></div>

This is similar to the property shorthand syntax when declaring objects in JavaScript. Note this is a feature that is only available in Vue 3.4 and above.

Boolean Attributes
​

Boolean attributes https://html.spec.whatwg.org/multipage/common-microsyntaxes.html#boolean-attributes are attributes that can indicate true / false values by their presence on an element. For example, disabled https://developer.mozilla.org/en-US/docs/Web/HTML/Reference/Attributes/disabled is one of the most commonly used boolean attributes.

v-bind works a bit differently in this case:
template

<button :disabled="isButtonDisabled">Button</button>

The disabled attribute will be included if isButtonDisabled has a truthy value https://developer.mozilla.org/en-US/docs/Glossary/Truthy. It will also be included if the value is an empty string, maintaining consistency with <button disabled="">. For other falsy values https://developer.mozilla.org/en-US/docs/Glossary/Falsy the attribute will be omitted.

Dynamically Binding Multiple Attributes
​

If you have a JavaScript object representing multiple attributes that looks like this:
js

const objectOfAttrs = {
id: 'container',
class: 'wrapper',
style: 'background-color:green'
}

You can bind them to a single element by using v-bind without an argument:
template

<div v-bind="objectOfAttrs"></div>

Using JavaScript Expressions
​

So far we've only been binding to simple property keys in our templates. But Vue actually supports the full power of JavaScript expressions inside all data bindings:
template

{{ number + 1 }}

{{ ok ? 'YES' : 'NO' }}

{{ message.split('').reverse().join('') }}

<div :id="`list-${id}`"></div>

These expressions will be evaluated as JavaScript in the data scope of the current component instance.

In Vue templates, JavaScript expressions can be used in the following positions:

    Inside text interpolations (mustaches)
    In the attribute value of any Vue directives (special attributes that start with v-)

Expressions Only
​

Each binding can only contain one single expression. An expression is a piece of code that can be evaluated to a value. A simple check is whether it can be used after return.

Therefore, the following will NOT work:
template

<!-- this is a statement, not an expression: -->

{{ var a = 1 }}

<!-- flow control won't work either, use ternary expressions -->

{{ if (ok) { return message } }}

Calling Functions
​

It is possible to call a component-exposed method inside a binding expression:
template

<time :title="toTitleDate(date)" :datetime="date">
  {{ formatDate(date) }}
</time>

TIP

Functions called inside binding expressions will be called every time the component updates, so they should not have any side effects, such as changing data or triggering asynchronous operations.

Restricted Globals Access
​

Template expressions are sandboxed and only have access to a restricted list of globals https://github.com/vuejs/core/blob/main/packages/shared/src/globalsAllowList.ts#L3. The list exposes commonly used built-in globals such as Math and Date.

Globals not explicitly included in the list, for example user-attached properties on window, will not be accessible in template expressions. You can, however, explicitly define additional globals for all Vue expressions by adding them to app.config.globalProperties https://vuejs.org/api/application.html#app-config-globalproperties.

Directives
​

Directives are special attributes with the v- prefix. Vue provides a number of built-in directives https://vuejs.org/api/built-in-directives.html, including v-html and v-bind which we have introduced above.

Directive attribute values are expected to be single JavaScript expressions (with the exception of v-for, v-on and v-slot, which will be discussed in their respective sections later). A directive's job is to reactively apply updates to the DOM when the value of its expression changes. Take v-if https://vuejs.org/api/built-in-directives.html#v-if as an example:
template

<p v-if="seen">Now you see me</p>

Here, the v-if directive would remove or insert the <p> element based on the truthiness of the value of the expression seen.
Arguments
​

Some directives can take an "argument", denoted by a colon after the directive name. For example, the v-bind directive is used to reactively update an HTML attribute:
template

<a v-bind:href="url"> ... </a>

<!-- shorthand -->

<a :href="url"> ... </a>

Here, href is the argument, which tells the v-bind directive to bind the element's href attribute to the value of the expression url. In the shorthand, everything before the argument (i.e., v-bind:) is condensed into a single character, :.

Another example is the v-on directive, which listens to DOM events:
template

<a v-on:click="doSomething"> ... </a>

<!-- shorthand -->

<a @click="doSomething"> ... </a>

Here, the argument is the event name to listen to: click. v-on has a corresponding shorthand, namely the @ character. We will talk about event handling in more detail too.
Dynamic Arguments
​

It is also possible to use a JavaScript expression in a directive argument by wrapping it with square brackets:
template

<!--
Note that there are some constraints to the argument expression,
as explained in the "Dynamic Argument Value Constraints" and "Dynamic Argument Syntax Constraints" sections below.
-->

<a v-bind:[attributeName]="url"> ... </a>

<!-- shorthand -->

<a :[attributeName]="url"> ... </a>

Here, attributeName will be dynamically evaluated as a JavaScript expression, and its evaluated value will be used as the final value for the argument. For example, if your component instance has a data property, attributeName, whose value is "href", then this binding will be equivalent to v-bind:href.

Similarly, you can use dynamic arguments to bind a handler to a dynamic event name:
template

<a v-on:[eventName]="doSomething"> ... </a>

<!-- shorthand -->

<a @[eventName]="doSomething"> ... </a>

In this example, when eventName's value is "focus", v-on:[eventName] will be equivalent to v-on:focus.
Dynamic Argument Value Constraints
​

Dynamic arguments are expected to evaluate to a string, with the exception of null. The special value null can be used to explicitly remove the binding. Any other non-string value will trigger a warning.
Dynamic Argument Syntax Constraints
​

Dynamic argument expressions have some syntax constraints because certain characters, such as spaces and quotes, are invalid inside HTML attribute names. For example, the following is invalid:
template

<!-- This will trigger a compiler warning. -->

<a :['foo' + bar]="value"> ... </a>

If you need to pass a complex dynamic argument, it's probably better to use a computed property https://vuejs.org/guide/essentials/computed.html, which we will cover shortly.

When using in-DOM templates (templates directly written in an HTML file), you should also avoid naming keys with uppercase characters, as browsers will coerce attribute names into lowercase:
template

<a :[someAttr]="value"> ... </a>

The above will be converted to :[someattr] in in-DOM templates. If your component has a someAttr property instead of someattr, your code won't work. Templates inside Single-File Components are not subject to this constraint.

Modifiers
​

Modifiers are special postfixes denoted by a dot, which indicate that a directive should be bound in some special way. For example, the .prevent modifier tells the v-on directive to call event.preventDefault() on the triggered event:
template

<form @submit.prevent="onSubmit">...</form>

You'll see other examples of modifiers later, for https://vuejs.org/guide/essentials/event-handling.html#event-modifiers v-on and for https://vuejs.org/guide/essentials/forms.html#modifiers v-model, when we explore those features.

And finally, here's the full directive syntax visualized:

directive syntax graph
v-on:submit.prevent="onSubmit"
v-on name starts with v- May be omitted when using shorthands
submit Argument Follows the colon or shorthand symbol
prevent Modifiers Denoted by the leading dot
onSubmit Value Interpreted as JavaScript expressions

## Reactivity Fundamentals

https://vuejs.org/guide/essentials/reactivity-fundamentals.html

Reactivity Fundamentals
​

API Preference

This page and many other chapters later in the guide contain different content for the Options API and the Composition API. Your current preference is Composition API. You can toggle between the API styles using the "API Preference" switches at the top of the left sidebar.
Declaring Reactive State
​
ref()
​

In Composition API, the recommended way to declare reactive state is using the ref() https://vuejs.org/api/reactivity-core.html#ref function:
js

import { ref } from 'vue'

const count = ref(0)

ref() takes the argument and returns it wrapped within a ref object with a .value property:
js

const count = ref(0)

console.log(count) // { value: 0 }
console.log(count.value) // 0

count.value++
console.log(count.value) // 1

    See also: Typing Refs https://vuejs.org/guide/typescript/composition-api.html#typing-ref

To access refs in a component's template, declare and return them from a component's setup() function:
js

import { ref } from 'vue'

export default {
// `setup` is a special hook dedicated for the Composition API.
setup() {
const count = ref(0)

    // expose the ref to the template
    return {
      count
    }

}
}

template

<div>{{ count }}</div>

Notice that we did not need to append .value when using the ref in the template. For convenience, refs are automatically unwrapped when used inside templates (with a few caveats https://vuejs.org/guide/essentials/reactivity-fundamentals.html#caveat-when-unwrapping-in-templates).

You can also mutate a ref directly in event handlers:
template

<button @click="count++">
{{ count }}
</button>

For more complex logic, we can declare functions that mutate refs in the same scope and expose them as methods alongside the state:
js

import { ref } from 'vue'

export default {
setup() {
const count = ref(0)

    function increment() {
      // .value is needed in JavaScript
      count.value++
    }

    // don't forget to expose the function as well.
    return {
      count,
      increment
    }

}
}

Exposed methods can then be used as event handlers:
template

<button @click="increment">
{{ count }}
</button>

Here's the example live on Codepen https://codepen.io/vuejs-examples/pen/WNYbaqo, without using any build tools.
`<script setup>`
​

Manually exposing state and methods via setup() can be verbose. Luckily, it can be avoided when using Single-File Components (SFCs) https://vuejs.org/guide/scaling-up/sfc.html . We can simplify the usage with `<script setup>`:

```vue
<script setup>
import { ref } from "vue";

const count = ref(0);

function increment() {
  count.value++;
}
</script>

<template>
  <button @click="increment">
    {{ count }}
  </button>
</template>
```

Try it in the Playground

Top-level imports, variables and functions declared in `<script setup>` are automatically usable in the template of the same component. Think of the template as a JavaScript function declared in the same scope - it naturally has access to everything declared alongside it.

TIP

For the rest of the guide, we will be primarily using SFC + <script setup> syntax for the Composition API code examples, as that is the most common usage for Vue developers.

If you are not using SFC, you can still use Composition API with the setup() https://vuejs.org/api/composition-api-setup.html option.

Why Refs?
​

You might be wondering why we need refs with the .value instead of plain variables. To explain that, we will need to briefly discuss how Vue's reactivity system works.

When you use a ref in a template, and change the ref's value later, Vue automatically detects the change and updates the DOM accordingly. This is made possible with a dependency-tracking based reactivity system. When a component is rendered for the first time, Vue tracks every ref that was used during the render. Later on, when a ref is mutated, it will trigger a re-render for components that are tracking it.

In standard JavaScript, there is no way to detect the access or mutation of plain variables. However, we can intercept the get and set operations of an object's properties using getter and setter methods.

The .value property gives Vue the opportunity to detect when a ref has been accessed or mutated. Under the hood, Vue performs the tracking in its getter, and performs triggering in its setter. Conceptually, you can think of a ref as an object that looks like this:
js

// pseudo code, not actual implementation
const myRef = {
\_value: 0,
get value() {
track()
return this.\_value
},
set value(newValue) {
this.\_value = newValue
trigger()
}
}

Another nice trait of refs is that unlike plain variables, you can pass refs into functions while retaining access to the latest value and the reactivity connection. This is particularly useful when refactoring complex logic into reusable code.

The reactivity system is discussed in more details in the Reactivity in Depth https://vuejs.org/guide/extras/reactivity-in-depth.html section.

Deep Reactivity
​

Refs can hold any value type, including deeply nested objects, arrays, or JavaScript built-in data structures like Map.

A ref will make its value deeply reactive. This means you can expect changes to be detected even when you mutate nested objects or arrays:
js

import { ref } from 'vue'

const obj = ref({
nested: { count: 0 },
arr: ['foo', 'bar']
})

function mutateDeeply() {
// these will work as expected.
obj.value.nested.count++
obj.value.arr.push('baz')
}

Non-primitive values are turned into reactive proxies via reactive(), which is discussed below.

It is also possible to opt-out of deep reactivity with shallow refs https://vuejs.org/api/reactivity-advanced.html#shallowref. For shallow refs, only .value access is tracked for reactivity. Shallow refs can be used for optimizing performance by avoiding the observation cost of large objects, or in cases where the inner state is managed by an external library.

Further reading:

    Reduce Reactivity Overhead for Large Immutable Structures https://vuejs.org/guide/best-practices/performance.html#reduce-reactivity-overhead-for-large-immutable-structures
    Integration with External State Systems https://vuejs.org/guide/extras/reactivity-in-depth.html#integration-with-external-state-systems

DOM Update Timing
​

When you mutate reactive state, the DOM is updated automatically. However, it should be noted that the DOM updates are not applied synchronously. Instead, Vue buffers them until the "next tick" in the update cycle to ensure that each component updates only once no matter how many state changes you have made.

To wait for the DOM update to complete after a state change, you can use the nextTick() https://vuejs.org/api/general.html#nexttick global API:
js

import { nextTick } from 'vue'

async function increment() {
count.value++
await nextTick()
// Now the DOM is updated
}

reactive()
​

There is another way to declare reactive state, with the reactive() API. Unlike a ref which wraps the inner value in a special object, reactive() makes an object itself reactive:
js

import { reactive } from 'vue'

const state = reactive({ count: 0 })

    See also: Typing Reactive https://vuejs.org/guide/typescript/composition-api.html#typing-reactive

Usage in template:
template

<button @click="state.count++">
{{ state.count }}
</button>

Reactive objects are JavaScript Proxies https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Proxy and behave just like normal objects. The difference is that Vue is able to intercept the access and mutation of all properties of a reactive object for reactivity tracking and triggering.

reactive() converts the object deeply: nested objects are also wrapped with reactive() when accessed. It is also called by ref() internally when the ref value is an object. Similar to shallow refs, there is also the shallowReactive() https://vuejs.org/api/reactivity-advanced.html#shallowreactive API for opting-out of deep reactivity.
Reactive Proxy vs. Original
​

It is important to note that the returned value from reactive() is a Proxy https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Proxy of the original object, which is not equal to the original object:
js

const raw = {}
const proxy = reactive(raw)

// proxy is NOT equal to the original.
console.log(proxy === raw) // false

Only the proxy is reactive - mutating the original object will not trigger updates. Therefore, the best practice when working with Vue's reactivity system is to exclusively use the proxied versions of your state.

To ensure consistent access to the proxy, calling reactive() on the same object always returns the same proxy, and calling reactive() on an existing proxy also returns that same proxy:
js

// calling reactive() on the same object returns the same proxy
console.log(reactive(raw) === proxy) // true

// calling reactive() on a proxy returns itself
console.log(reactive(proxy) === proxy) // true

This rule applies to nested objects as well. Due to deep reactivity, nested objects inside a reactive object are also proxies:
js

const proxy = reactive({})

const raw = {}
proxy.nested = raw

console.log(proxy.nested === raw) // false

Limitations of reactive()
​

The reactive() API has a few limitations:

    Limited value types: it only works for object types (objects, arrays, and collection types https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects#keyed_collections such as Map and Set). It cannot hold primitive types https://developer.mozilla.org/en-US/docs/Glossary/Primitive such as string, number or boolean.

    Cannot replace entire object: since Vue's reactivity tracking works over property access, we must always keep the same reference to the reactive object. This means we can't easily "replace" a reactive object because the reactivity connection to the first reference is lost:

js

let state = reactive({ count: 0 })

// the above reference ({ count: 0 }) is no longer being tracked
// (reactivity connection is lost!)
state = reactive({ count: 1 })

Not destructure-friendly: when we destructure a reactive object's primitive type property into local variables, or when we pass that property into a function, we will lose the reactivity connection:

    js

    const state = reactive({ count: 0 })

    // count is disconnected from state.count when destructured.
    let { count } = state
    // does not affect original state
    count++

    // the function receives a plain number and
    // won't be able to track changes to state.count
    // we have to pass the entire object in to retain reactivity
    callSomeFunction(state.count)

Due to these limitations, we recommend using ref() as the primary API for declaring reactive state.
Additional Ref Unwrapping Details
​
As Reactive Object Property
​

A ref is automatically unwrapped when accessed or mutated as a property of a reactive object. In other words, it behaves like a normal property:
js

const count = ref(0)
const state = reactive({
count
})

console.log(state.count) // 0

state.count = 1
console.log(count.value) // 1

If a new ref is assigned to a property linked to an existing ref, it will replace the old ref:
js

const otherCount = ref(2)

state.count = otherCount
console.log(state.count) // 2
// original ref is now disconnected from state.count
console.log(count.value) // 1

Ref unwrapping only happens when nested inside a deep reactive object. It does not apply when it is accessed as a property of a shallow reactive object https://vuejs.org/api/reactivity-advanced.html#shallowreactive.
Caveat in Arrays and Collections
​

Unlike reactive objects, there is no unwrapping performed when the ref is accessed as an element of a reactive array or a native collection type like Map:
js

const books = reactive([ref('Vue 3 Guide')])
// need .value here
console.log(books[0].value)

const map = reactive(new Map([['count', ref(0)]]))
// need .value here
console.log(map.get('count').value)

Caveat when Unwrapping in Templates
​

Ref unwrapping in templates only applies if the ref is a top-level property in the template render context.

In the example below, count and object are top-level properties, but object.id is not:
js

const count = ref(0)
const object = { id: ref(1) }

Therefore, this expression works as expected:
template

{{ count + 1 }}

...while this one does NOT:
template

{{ object.id + 1 }}

The rendered result will be [object Object]1 because object.id is not unwrapped when evaluating the expression and remains a ref object. To fix this, we can destructure id into a top-level property:
js

const { id } = object

template

{{ id + 1 }}

Now the render result will be 2.

Another thing to note is that a ref does get unwrapped if it is the final evaluated value of a text interpolation (i.e. a {{ }} tag), so the following will render 1:
template

{{ object.id }}

This is just a convenience feature of text interpolation and is equivalent to {{ object.id.value }}.

## Computed Properties

https://vuejs.org/guide/essentials/computed.html

## Class and Style Bindings

https://vuejs.org/guide/essentials/class-and-style.html

## Conditional Rendering

https://vuejs.org/guide/essentials/conditional.html

## List Rendering

https://vuejs.org/guide/essentials/list.html

## Event Handling

https://vuejs.org/guide/essentials/event-handling.html

## Form Input Bindings

https://vuejs.org/guide/essentials/forms.html

## Watchers

https://vuejs.org/guide/essentials/watchers.html

## Template Refs

https://vuejs.org/guide/essentials/template-refs.html

## Components Basics

https://vuejs.org/guide/essentials/component-basics.html

## Lifecycle Hooks

https://vuejs.org/guide/essentials/lifecycle.html

# Components In-Depth

## Registration

https://vuejs.org/guide/components/registration.html

## Props

https://vuejs.org/guide/components/props.html

## Events

https://vuejs.org/guide/components/events.html

## Component v-model

https://vuejs.org/guide/components/v-model.html

## Fallthrough Attributes

https://vuejs.org/guide/components/attrs.html

## Slots

https://vuejs.org/guide/components/slots.html

## Provide / inject

https://vuejs.org/guide/components/provide-inject.html

## Async Components

https://vuejs.org/guide/components/async.html

# Reusability

## Composables

https://vuejs.org/guide/reusability/composables.html

## Custom Directives

https://vuejs.org/guide/reusability/custom-directives.html

## Plugins

https://vuejs.org/guide/reusability/plugins.html

# Built-in Components

## Transition

https://vuejs.org/guide/built-ins/transition

## TransitionGroup

https://vuejs.org/guide/built-ins/transition-group

## KeepAlive

https://vuejs.org/guide/built-ins/keep-alive

## Teleport

https://vuejs.org/guide/built-ins/teleport

## Suspense

https://vuejs.org/guide/built-ins/suspense

# Scaling Up

## Single-File Components

https://vuejs.org/guide/scaling-up/sfc.html

## Tooling

https://vuejs.org/guide/scaling-up/tooling.html

## Routing

https://vuejs.org/guide/scaling-up/routing.html

## State Management

https://vuejs.org/guide/scaling-up/state-management.html

## Testing

https://vuejs.org/guide/scaling-up/testing.html

## Server-Side Rendering (SSR)

https://vuejs.org/guide/scaling-up/ssr.html

# Best Practices

## Production Deployment

https://vuejs.org/guide/best-practices/production-deployment.html

## Performance

https://vuejs.org/guide/best-practices/performance.html

## Accessibility

https://vuejs.org/guide/best-practices/accessibility.html

## Security

https://vuejs.org/guide/best-practices/security.html

# TypeScript

## Overview

https://vuejs.org/guide/typescript/overview.html

## TS with Composition API

https://vuejs.org/guide/typescript/composition-api.html

## TS with Options API

https://vuejs.org/guide/typescript/options-api.html

# Extra Topics

## Ways of Using Vue

https://vuejs.org/guide/extras/ways-of-using-vue.html

## Composition API FAQ

https://vuejs.org/guide/extras/composition-api-faq.html

## Reactivity in Depth

https://vuejs.org/guide/extras/reactivity-in-depth.html

## Rendering Mechanism

https://vuejs.org/guide/extras/rendering-mechanism.html

## Render Functions & JSX

https://vuejs.org/guide/extras/render-function.html

## Vue and Web Components

https://vuejs.org/guide/extras/web-components.html

## Animation Techniques

https://vuejs.org/guide/extras/animation.html

# API

https://vuejs.org/api/
